
#ifndef _ECSERVER_POOLT_H_
#define _ECSERVER_POOLT_H_

#include "Define.h"
#include "MutexLock.h"

#define MAX_POOL_BUF    20000

using namespace std;

template <typename TYPE>
class PoolT
{
public:

    PoolT (int n = MAX_POOL_BUF)
    {
        this->m_size = n;
        for  (int i = 0; i < this->m_size; i++)
        {
            TYPE* p = new TYPE;
            this->m_free_queue.push (p);
        }
    }

    ~PoolT ()
    {
        MutexLockGuard guard (m_lock);
        while (!m_free_queue.empty ())
        {
            TYPE* p = this->m_free_queue.front ();
            this->m_free_queue.pop ();
            delete p;
        }
    }

    TYPE* malloc ()
    {
        MutexLockGuard guard (m_lock);
        if  (m_free_queue.empty ())
        {
            return NULL;
        }
        TYPE* p = m_free_queue.front ();
        m_free_queue.pop ();
        return p;
    }

    int free (TYPE* i)
    {
        MutexLockGuard guard (m_lock);
        m_free_queue.push (i);
        return 0;
    }

    int size ()
    {
        return m_size;
    }

    int used ()
    {
        MutexLockGuard guard (m_lock);
        return m_size - m_free_queue.size ();
    }

private:
    std::queue <TYPE*> m_free_queue;
    std::vector <TYPE*> m_used_queue;
    MutexLock m_lock;
    int m_size;
};

#endif
