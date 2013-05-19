
#include "EventLoop.h"

struct ev_loop* EventLoop::loop = NULL;
struct ev_io_info EventLoop::ioarray [MAXFD];
Atomic <int> EventLoop::clientcount;

EventLoop::EventLoop (string ip, int port)
{
    m_ip = ip;
    m_port = port;
    m_listenfd = socket (AF_INET, SOCK_STREAM, 0);
    setnonblock (m_listenfd);
    setreuseaddr (m_listenfd);
    setnodelay (m_listenfd);
    for (int i = 0; i< MAXFD; ++i)
    {
        ioarray[i].io = NULL;
    }
}

EventLoop::~EventLoop ()
{
    close (m_listenfd);
}

int EventLoop::startlisten ()
{
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr (m_ip.c_str ());
    //inet_pton  (AF_INET, m_ip.c_str (), &servaddr.sin_addr.s_addr);
    //servaddr.sin_addr.s_addr = htonl  (INADDR_ANY);
    servaddr.sin_port = htons (m_port);
    if (bind (m_listenfd, (struct sockaddr*) &servaddr, sizeof (struct sockaddr)) != 0)
    {
        LOG (ERROR) << "bind error %s" << strerror (errno) << endl;;
        sleep (1);
        abort (); //致命错误
        return (-1);
    }
    listen (m_listenfd, 10);
    return (m_listenfd);
}

int EventLoop::work ()
{
    startlisten ();
    ev_io *ev_io_watcher = (ev_io*) malloc (sizeof (ev_io));
#if 0
    //ev_io ev_io_watcher;
    //ev_timer timer;
#endif
    EventLoop::loop = ev_loop_new (EVBACKEND_EPOLL);

    ev_io_init (ev_io_watcher, accept_cb, m_listenfd, EV_READ);

    ev_io_start (EventLoop::loop, ev_io_watcher); 
#if 0
    //定时器
    ev_timer_init (&timer, time_cb, 5, 5);
    ev_timer_start (EventLoop::loop,&timer); 
#endif
    LOG (INFO) << "libevent loop";

    ev_loop (EventLoop::loop, 0);

    ev_loop_destroy (EventLoop::loop);
    free (ev_io_watcher);
    return (0);
}

void EventLoop::accept_cb (struct ev_loop *loop, ev_io *w, int revents)
{
    struct sockaddr_in clientaddr;
    socklen_t socklen = sizeof (struct sockaddr_in);
    int newfd = accept (w->fd, (struct sockaddr*)&clientaddr, &socklen);
    if (newfd <= 0)
    {
        return;
    }

    printf ("Client connected! fd = [%d] ip = [%s] port=[%d]\n",
            newfd,
            inet_ntoa (clientaddr.sin_addr),
            htons (clientaddr.sin_port) );

    LOG (INFO) << "Client connected! fd = [" << newfd 
        <<"] ip = ["<<inet_ntoa (clientaddr.sin_addr)
        <<"] port = [" << htons (clientaddr.sin_port) <<"]"<<endl;

    EventLoop::setnonblock (newfd);

    EventLoop::ioarray[newfd].io = (ev_io*)malloc (sizeof (ev_io));
    EventLoop::ioarray[newfd].lasttime = ev_time ();

    ev_io_init (EventLoop::ioarray[newfd].io, recv_cb, newfd, EV_READ);
    ev_io_start (loop, EventLoop::ioarray[newfd].io);
    EventLoop::clientcount++;

    return;
}

void EventLoop::recv_cb (struct ev_loop *loop, ev_io *w, int revents)
{
    Buffer* buf = GLOBAL->bufpool.malloc ();
    if (buf == NULL)
    {
        sleep  (1);
        printf ("--null buf\n");
        abort  ();
        return;
    }

    // check header of packet
    int i = recv_v (w->fd, buf->ptr (), sizeof (int));
    if (sizeof (int) != i)
    {
        LOG (ERROR) << w->fd <<":recv head error! actually received len = "<< i 
            <<" info = "<< strerror (errno)<<endl;
        GLOBAL->bufpool.free (buf);
        EventLoop::closefd (w->fd);
        return;
    }

    // recv body of packet
    int *p = (int*)buf->ptr ();
    i = recv_v (w->fd, (char*)buf->ptr () + sizeof (int), *p - sizeof (unsigned int));

    if ((*p - sizeof (unsigned int)) != (unsigned int) i) 
    {
        LOG (ERROR) << w->fd <<":recv body error! hope = "<< *p <<" actually received len = "<< i 
            <<" info = "<< strerror (errno) <<endl;
        GLOBAL->bufpool.free (buf);
        EventLoop::closefd (w->fd);
        return;
    }

    EventLoop::ioarray[w->fd].lasttime = ev_time ();
    buf->setfd (w->fd);
    //将buf压入队列
    GLOBAL->recvqueue.enqueue (buf);
    return;
}

void EventLoop::setnonblock (int fd)
{
    fcntl (fd, F_SETFL, fcntl (fd, F_GETFL, 0) | O_NONBLOCK);
}

void EventLoop::setreuseaddr (int fd)
{
    int reuse = 1;
    setsockopt (fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof (reuse));
}

void EventLoop::setnodelay (int fd)
{
    int nodelay = 1;
    setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof (nodelay));
}

void EventLoop::closefd (int fd)
{
    struct sockaddr_in remote_addr;
    socklen_t socklen = sizeof (struct sockaddr_in);
    getpeername (fd, (struct sockaddr*)&remote_addr, &socklen);

    printf ("Client disconnected! fd = [%d] ip = [%s] port=[%d]\n",
            fd,
            inet_ntoa (remote_addr.sin_addr),
            htons (remote_addr.sin_port) );

    LOG (INFO) << "Client disconnected! fd = [" << fd 
        <<"] ip = ["<< inet_ntoa (remote_addr.sin_addr)
        <<"] port = [" << htons (remote_addr.sin_port) <<"]"<<endl;

    close (fd);
    ev_io_stop (loop, EventLoop::ioarray[fd].io);
    free (EventLoop::ioarray[fd].io);
    EventLoop::ioarray[fd].io = NULL;
    EventLoop::clientcount--;
    //ROOMMANAGER->del_client (fd);
}

void EventLoop::time_cb (struct ev_loop* loop, struct ev_timer *timer, int revents)
{
    ev_tstamp now = ev_time ();
    for (register int i = 0; i < MAXFD; ++i)
    {
        if (ioarray[i].io != NULL)
        {
            //检测超时断开
            if (TIMEOUT < now - ioarray[i].lasttime)
            {
                LOG (INFO) << i << " now: "<< now << " last recv data:" << ioarray[i].lasttime ;
                //EventLoop::closefd (i);
            }
        }
    }
    return;
}

int EventLoop::getClientCount ()
{
    return (EventLoop::clientcount.value ());
}
