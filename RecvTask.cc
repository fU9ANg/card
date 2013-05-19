
#include "RecvTask.h"
#include "Message.h"

RecvTask::RecvTask ()
{
}

RecvTask::~RecvTask ()
{
}

int RecvTask::work ()
{
    while (true)
    {
        Buffer* p = NULL;
        if (GLOBAL->recvqueue.dequeue (p, 3) != 0)
        {
            continue;
        }

        if (p == NULL)
        {
            cout << "ERROR: p==NULL in RecvTask::work()" << endl;
            return (0);
        }

        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        if (head != NULL)
        {
            debugProtocol (p);
            cout << "recvTask: cType=" << head->cType << endl;
            handlefunc pfun = CHandleMessage::getHandler (head->cType); 
            if (pfun == NULL)
            {
                printf ("ERROR: the pointer of callback, cType=[%d]\n", head->cType);
                continue;
            }
            pfun (p);
        }
    }
    return (0);
}
