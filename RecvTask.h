
#ifndef RECVTASK_H_
#define RECVTASK_H_

#include "Define.h"
#include "Task.h"
#include "Utils.h"
#include "Global.h"
#include "Buffer.h"
#include "Protocol.h"

class RecvTask: public Task
{
    public:
         RecvTask ();
        ~RecvTask ();

    public:
        virtual int work ();
};

#endif
