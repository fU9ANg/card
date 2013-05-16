
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
        pthread_mutex_init (&_mutex, NULL);
        pthread_cond_init  (&_cond , NULL);
    }

    ~BlockQueue ()
    {
        pthread_mutex_destroy (&_mutex);
        pthread_cond_destroy  (&_cond);
    }

    int dequeue (TYPE& out, unsigned int timeout)
    {
        struct timespec t;

        pthread_mutex_lock (&_mutex);

        t.tv_sec = time (NULL) + timeout;
        t.tv_nsec = 0;

        while (_queue.empty ())
        {
            if (pthread_cond_timedwait (&_cond, &_mutex, &t) != 0)
            {
                //timeout
                pthread_mutex_unlock (&_mutex);
                return (-1);
            } 
        }
        out = _queue.front ();
        _queue.pop ();
        pthread_mutex_unlock (&_mutex);

        return (0);
    }

    int enqueue (TYPE t)
    {
        pthread_mutex_lock (&_mutex);

        if (_queue.empty ())
        {
            _queue.push (t);
            pthread_mutex_unlock (&_mutex);
            pthread_cond_signal (&_cond);
        }
        else
        {
            _queue.push (t);
            pthread_mutex_unlock (&_mutex);
        }

        return (0);
    }

    size_t size ()
    {
        pthread_mutex_lock (&_mutex);
        size_t size = _queue.size ();
        pthread_mutex_unlock (&_mutex);
        return (size);
    }

private:
    pthread_mutex_t _mutex;
    pthread_cond_t  _cond;
    queue <TYPE>    _queue;
};

#endif
