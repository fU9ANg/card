
#ifndef SENDTASK_H_
#define SENDTASK_H_

#include "Define.h"
#include "Task.h"
#include "Utils.h"
#include "Global.h"
#include "Buffer.h"

class SendTask: public Task
{
    public:
         SendTask ();
        ~SendTask ();

    public:
        virtual int work ();
};

#endif
