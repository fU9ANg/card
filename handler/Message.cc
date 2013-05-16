
/*
 * message.cpp
 */
#if 1
#include "Message.h"

#include "Protocol.h"
#include "Buffer.h"
#include "BufferSafe.h"
#include "Global.h"
#endif
/////////////////////
HANDLEMAP CHandleMessage::m_HandleMap;


/*
=====================
 转发信息的通用接口
=====================
*/
bool CHandleMessage::postMessage (Buffer* p, enum CommandType iCommandType, void* data, unsigned int iLen)
{
    //cout << "postMessage.........." << endl;
    if (p == NULL)
        return false;

    MSG_HEAD* head = (MSG_HEAD*)p->ptr();
    head->cLen = sizeof (MSG_HEAD);
    head->cType = iCommandType;

    if (data != NULL) {
        head->cLen = head->cLen + iLen;
        (void) memcpy ((char*)p->ptr() + sizeof (MSG_HEAD), (char*)data, iLen);
    }

    p->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (p);

    return true;
}

void CHandleMessage::postTest (void)
{
    BUFFER (p);
    SINGLE->bufpool.free (p);
    p->setsize (10);
}
