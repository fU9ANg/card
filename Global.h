
#ifndef _GLOBAL_DATA_H_
#define _GLOBAL_DATA_H_

#include "Define.h"

#include "Atomic.h"
#include "BlockQueue.h"
#include "MemZone.h"
#include "Buffer.h"

class Single 
{
    public:
        ~Single();
        static class Single* instance();
        BlockQueue<Buffer*> recvqueue;
        BlockQueue<Buffer*> sendqueue;
        PoolT    <Buffer> bufpool;

    private:
        Single();
        static class Single* p_;
};

#define SINGLE Single::instance()

#endif
