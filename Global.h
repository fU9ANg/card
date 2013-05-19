
#ifndef _GLOBAL_DATA_H_
#define _GLOBAL_DATA_H_

#include "Define.h"

#include "Atomic.h"
#include "BlockQueue.h"
#include "MemZone.h"
#include "Buffer.h"

class Global 
{
    public:
        ~Global();
        static class Global* instance();
        BlockQueue<Buffer*> recvqueue;
        BlockQueue<Buffer*> sendqueue;
        MemZone   <Buffer > bufpool;

    private:
        Global();
        static class Global* p_;
};

#define GLOBAL Global::instance()

#endif
