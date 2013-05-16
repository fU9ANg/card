
/*
 * HandleMessage.h
 */

#ifndef _HANDLE_MESSAGE_H
#define _HANDLE_MESSAGE_H

#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "Protocol.h"
#include "Global.h"
#include "Buffer.h"
#include "SQL.h"

using namespace std;

#define _EXECUTE_

typedef void (*handlefunc)(Buffer*);
typedef map<int, handlefunc> HANDLEMAP;

class CHandleMessage
{
public:

    #define MSGNAME(name, handle) static void handle (Buffer* p)
    #include "MSGHANDLE"
    #undef MSGNAME

public:
    static handlefunc getHandler (int iCommandType)
    {
        HANDLEMAP::iterator it = CHandleMessage::m_HandleMap.find(iCommandType);
        if (it != CHandleMessage::m_HandleMap.end())
            return it->second;

        return NULL;
    }

    static void initHandlers (void)
    {
        #define MSGNAME(name, handle) \
            CHandleMessage::setHandler (name, &CHandleMessage::handle)
        #include "MSGHANDLE"
        #undef MSGNAME
    }

    static void setHandler (int iCommandType, handlefunc hHandler)
    {
        if (hHandler != NULL)
            m_HandleMap.insert (std::pair<int, handlefunc>(iCommandType, hHandler));
    }

private:
    static bool postMessage (Buffer* p, enum CommandType iCommandType, void* data, unsigned int iLen);
    static void postTest (void);

private:
    static HANDLEMAP m_HandleMap;

public:

};


#endif //_HANDLE_MESSAGE_H
