
#ifndef _CARDSRV_ATOMIC_H_
#define _CARDSRV_ATOMIC_H_

#include "Define.h"
#include "MutexLock.h"

template <typename TYPE>
class Atomic
{
    public:
        Atomic()
        {
            m_value = 0;
        }

        Atomic(TYPE a)
        {
            m_value = a;
        }

        ~Atomic()
        {
        }

        TYPE value()
        {
            MutexLockGuard guard (m_lock);
            return this->m_value;
        }

        TYPE operator+= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value += a;
        }

        TYPE operator-= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value -= a;
        }

        TYPE operator++ (void)
        {
            MutexLockGuard guard (m_lock);
            return ++this->m_value;
        }

        TYPE operator++ (int)   // parameter must is int type
        {
            MutexLockGuard guard (m_lock);
            return this->m_value++;
        }

        TYPE operator-- (void)
        {
            MutexLockGuard guard (m_lock);
            return --this->m_value;
        }

        TYPE operator-- (int)  // parameter must is int type
        {
            MutexLockGuard guard (m_lock);
            return this->m_value--;
        }

        Atomic<TYPE>& operator= (TYPE a)
        {
            Atomic<TYPE> tmp (a);
            MutexLockGuard guard (m_lock);
            std::swap (this->m_value, tmp.m_value);
            return *this;
        }

        bool operator== (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value == a;
        }

        bool operator!= (TYPE a) 
        {
            MutexLockGuard guard (m_lock);
            return this->m_value != a;
        }

        bool operator> (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value > a;
        }

        bool operator>= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value >= a;
        }

        bool operator< (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value < a;
        }

        bool operator<= (TYPE a)
        {
            MutexLockGuard guard (m_lock);
            return this->m_value <= a;
        }

    private:
        TYPE      m_value;
        MutexLock m_lock;
};

typedef Atomic<char>            ATOMICCHAR;
typedef Atomic<short>           ATOMICSHORT;
typedef Atomic<int>             ATOMICINT;
typedef Atomic<long>            ATOMICLONG;
typedef Atomic<long long>       ATOMICLL;

typedef Atomic<unsigned char>   ATOMICUCHAR;
typedef Atomic<unsigned short>  ATOMICUSHORT;
typedef Atomic<unsigned int>    ATOMICUINT;

#endif  // _CARDSRV_ATOMIC_H_
