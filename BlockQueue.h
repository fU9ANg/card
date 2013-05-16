
#ifndef _BLOCKQUEUE_H_
#define _BLOCKQUEUE_H_

#include "Define.h"
#include "MutexLock.h"

using namespace std;

template<typename TYPE>
class BlockQueue
{
public:

    BlockQueue ()
    {
        pthread_mutex_init (&m_mutex, NULL);
        pthread_cond_init (&m_con, NULL);
    }

    ~BlockQueue ()
    {
        pthread_mutex_destroy (&m_mutex);
        pthread_cond_destroy (&m_con);
    }

    int dequeue (TYPE& out, unsigned int timeout)
    {
        struct timespec t;
        t.tv_sec = time (NULL) + timeout;
        t.tv_nsec = 0;
        pthread_mutex_lock (&m_mutex);
        while (m_queue.empty ()) {
            if (0 != pthread_cond_timedwait (&m_con, &m_mutex, &t)) {
                //timeout
                pthread_mutex_unlock (&m_mutex);
                return (-1);
            } 
        }
        out = m_queue.front ();
        m_queue.pop ();
        pthread_mutex_unlock (&m_mutex);
        return (0);
    }

    int enqueue (TYPE t)
    {
        pthread_mutex_lock (&m_mutex);
        if (m_queue.empty ())
        {
            m_queue.push (t);
            pthread_mutex_unlock (&m_mutex);
            pthread_cond_signal (&m_con);
        }
        else
        {
            m_queue.push (t);
            pthread_mutex_unlock (&m_mutex);
        }

        return (0);
    }

    size_t size ()
    {
        pthread_mutex_lock (&m_mutex);
        size_t size = m_queue.size ();
        pthread_mutex_unlock (&m_mutex);
        return (size);
    }

private:
    pthread_mutex_t m_mutex;
    pthread_cond_t  m_con;
    queue <TYPE>    m_queue;
};

#endif
