
#ifndef _CARDSRV_BUFFERSAFE_H
#define _CARDSRV_BUFFERSAFE_H

#include "Buffer.h"
#include "Global.h"

class BufferSafe
{
    public:
        explicit BufferSafe (Buffer* _buf)
        {
            _buf = SINGLE->bufpool.malloc ();
        }
        
        ~BufferSafe ()
        {
            SINGLE->bufpool.free (_buffer);
        }
        
    private:
        BufferSafe (const BufferSafe& t);
        const BufferSafe& operator= (const BufferSafe&);
        Buffer* _buffer;
};

#endif // _CARDSRV_BUFFERSAFE_H
