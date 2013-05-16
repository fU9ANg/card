
#ifndef _CARDSRV_BUF_H_
#define _CARDSRV_BUF_H_

#include "Define.h"

#define     MAX_BUF     5120

class Buffer
{
public:
    Buffer (size_t inSize = MAX_BUF)
    {
        m_size  = inSize;
        m_ptr   = malloc (m_size);
        m_curr_ptr = m_ptr;
        m_fd    = 0;
        m_id    = 0;
    };

    ~Buffer ()
    {
        if (m_ptr != NULL)
        {
            free (m_ptr);
            m_ptr = NULL;
            m_curr_ptr = NULL;
        }
    }

    Buffer (Buffer& b)
    {
        m_size = b.m_size;
        this->m_ptr = malloc (m_size);
        this->m_curr_ptr = this->m_ptr;
        memcpy (this->m_ptr, b.m_ptr, m_size);
    };

    void* ptr ()
    {
        return (m_ptr);
    }

    void* current_ptr()
    {
        return (m_curr_ptr);
    }

    size_t setsize (size_t in)
    {
        return m_used = in;
    }

    size_t maxsize ()
    {
        return m_size;
    }

    size_t size ()
    {
        return m_used;
    }

    void reset ()
    {
        memset (m_ptr, 0x00, m_size);
        m_curr_ptr = m_ptr;
    }

    int getfd ()
    {
        return m_fd;
    }

    void setfd (int fd)
    {
        m_fd = fd;
    }

    int getid ()
    {
        return m_id;
    }

    void setid (int id)
    {
        m_id = id;
    }

    Buffer& operator= (Buffer& b)
    {
        memcpy (this->m_ptr, b.ptr (), m_size);
        return *this;
    }

    // operators
#if 0
    void operator<< (TYPE t)
    {
        (void) memcpy ((char*) m_curr_ptr, (char*) t, sizeof (TYPE));
        m_curr_ptr += sizeof (TYPE);
    }
#endif
private:
    void*   m_ptr;
    void*   m_curr_ptr;
    size_t  m_size;
    size_t  m_used;
    int     m_fd;
    int     m_id;
};

class BufferSafe;

#define BUFFER(p) \
    Buffer* p = NULL; \
    BufferSafe bs(p);

#endif  // _CARDSRV_BUF_H
