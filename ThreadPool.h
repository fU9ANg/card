
#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include "Define.h"
#include "BlockQueue.h"
#include "Task.h"
#include "Atomic.h"
#include "MutexLock.h"

class ThreadPool
{
    public:
        ThreadPool (int n);
        ~ThreadPool ();
        int start ();
        int stop ();
        int kill ();
        int push_task (Task* p);
        static void* thread (void* p);
        static void sighandle (int signo);
        int getcount ();
        int getfree ();

    private:
        list <pthread_t> _threads;
        BlockQueue <Task*> _taskQueue;
        Atomic <int> _state;
        Atomic <int> _free;
        int count;
        MutexLock _listLock;
};

#endif
