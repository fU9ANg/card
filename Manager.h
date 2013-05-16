
#ifndef _CARDSRV_MAMAGER_H_
#define _CARDSRV_MAMAGER_H_

#include "Define.h"

#include "glog/logging.h"

#include "ThreadPool.h"
#include "Task.h"
#include "RecvTask.h"
#include "SendTask.h"
#include "EventLoop.h"
#include "Buffer.h"

#include "Manager.h"

#define CONFIGFILE "./config.lua"

enum
{
    LOCK_WAIT   = LOCK_EX,            /* 阻塞锁 */
    LOCK_NOWAIT = LOCK_EX | LOCK_NB,  /* 非阻塞锁 */
    UNLOCK      = LOCK_UN             /* 解锁 */
};

class manager
{
    public:
        manager ();
        ~manager ();

        int execute (int argc, char** argv);
        int run ();
        static void sig_term (int signo);

    private:
        bool lock (int mode);
        ThreadPool* m_thrpool;
        int m_lockfd;            /**文件锁句柄*/
};

#endif // _CARDSRV_MAMAGER_H_
