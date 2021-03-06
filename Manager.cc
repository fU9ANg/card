
#include "Manager.h"

manager::manager()
{
    m_thrpool = new ThreadPool (5);
    m_lockfd = 0;
}

manager::~manager()
{
    // TODO:
}

int manager::execute (int argc, char** argv)
{
    //设置信号处理
    signal (SIGINT, SIG_IGN);
    signal (SIGPIPE, SIG_IGN);
    signal (SIGQUIT, SIG_IGN);
    signal (SIGTERM, sig_term);

    int opt = getopt (argc, argv, "udsv");
    if (opt == -1)
    {
        printf("argv error\n");
        return -1;
    }

    int pid = 0;
    switch (opt)
    {
        case 's':
            pid = fork();
            if (0 < pid)
                return (0);
            break;

        case 'd':
            if (lock (LOCK_NOWAIT) != true)
            {
                printf("Server already running!\n");
                return (0);
            } 
            //初始化日志 
            assert (0 == system ("mkdir -p logs"));
            google::InitGoogleLogging (argv[0]);
            google::SetLogDestination (google::INFO, "./logs/info");
            google::SetLogDestination (google::WARNING, "./logs/warning");
            google::SetLogDestination (google::ERROR, "./logs/error");
            google::SetStderrLogging  (google::ERROR + 1);
            //配置输出到标准错误的最低日志级别,使error日志不打屏
            CONFIG->readconfig (CONFIGFILE);
            if (!DATABASE->Init(CONFIG->db_host, \
                                CONFIG->db_username, \
                                CONFIG->db_password, \
                                CONFIG->db_database))
            {
                printf("[ERROR] -- Database: Please check database configure file\n");
                return 0;
            }
            //启动
            this->run ();
            break;
            
    case 'u':
        if (lock (LOCK_NOWAIT) == true)
        {   
            lock (UNLOCK);
            printf ("No process!\n");
        }
        else 
        {
            printf ("Find process! stopping...\n");
            assert(0 == system ("cat .lock|xargs kill -15"));
        }

        printf ("stop\n");
        break;
        
    case 'v':
        printf ("compiled at %s,%s\n",__DATE__,__TIME__);
        break;
        
    default:
        break;
    }

    return (0);
}

void manager::sig_term (int signo)
{
    printf ("get exit signal\n");
    LOG (INFO) << "server stoped";
    raise (SIGKILL);
    raise (SIGRTMIN);
    //m_thrpool->kill ();
    return;
}

int manager::run ()
{
    printf ("server running...\n");

    m_thrpool->start ();
    EventLoop* evloop = new EventLoop (CONFIG->server_ip.c_str(), CONFIG->server_port);
    printf ("server ip = [%s], port = [%d]\n", CONFIG->server_ip.c_str (), CONFIG->server_port);
    RecvTask* precv = new RecvTask ();
    SendTask* psend = new SendTask ();
    //BHSyncTask* psync = new BHSyncTask ();

    //ROOMMANAGER->init ();
    //CHandleMessage::initHandlers ();
    //printf ("[%d] class init success!\n", ROOMMANAGER->get_room_count ());

    m_thrpool->push_task (evloop);//监听和数据接收线程
    m_thrpool->push_task (precv);//数据处理线程
    //m_thrpool->push_task(precv);//数据处理线程
    //m_thrpool->push_task(psend);
    m_thrpool->push_task (psend);

    //m_thrpool->push_task (psync);

    LOG(INFO) << "server start success!";

    //主线程死循环
    while (true)
    {
        //cout<<"new client count = "<<evloop->getClientCount ()<<endl;
        LOG (INFO) << "new client count = " << evloop->getClientCount () << endl;
        sleep (5);
    }

    m_thrpool->kill ();
    return (0);
}

bool manager::lock (int mode)
{
    char szPid[32] = {0};
    snprintf (szPid, 32, "%ld", (long) getpid ());

    if (m_lockfd == 0)
    {
        m_lockfd = open ("./.lock", O_RDWR|O_CREAT, 0640);
    }

    if (m_lockfd < 0)
    {
        return (false);
    }

    if (flock (m_lockfd, mode) != 0)
    {
        return (false);
    }

    if (UNLOCK == mode)
    {
        close (m_lockfd);
    }
    else
    {
        if (ftruncate (m_lockfd, 0) == 0)
        {
            if (write (m_lockfd, szPid, strlen (szPid)) <= 0) 
            {
                printf ("write pid file error!\n");
            }
        }
        else
        {
            printf ("write pid file error!\n");
            sleep (1);
            abort ();
        }
    }
    return (true);
}
