
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
        m_in_ptr = m_ptr;
        m_out_ptr = m_ptr;
        m_fd    = 0;
        m_id    = 0;
    };

    ~Buffer ()
    {
        if (m_ptr != NULL)
        {
            free (m_ptr);
            m_ptr = NULL;
            m_in_ptr = NULL;
            m_out_ptr = NULL;
        }
    }

    Buffer (Buffer& b)
    {
        m_size = b.m_size;
        this->m_ptr = malloc (m_size);
        this->m_in_ptr = this->m_ptr;
        this->m_out_ptr = this->m_ptr;
        memcpy (this->m_ptr, b.m_ptr, m_size);
    };

    void* ptr ()
    {
        return (m_ptr);
    }

    void* input_ptr()
    {
        return (m_in_ptr);
    }

    void* output_ptr()
    {
        return (m_out_ptr);
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
        m_in_ptr = m_ptr;
        m_out_ptr = m_ptr;
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
    template <typename TYPE>
    void operator<< (TYPE& pt)
    {
        if (m_in_ptr)
        {
            (void) memcpy ((char*) m_in_ptr, (char*) &pt, sizeof (TYPE));
            m_in_ptr = (char*) m_in_ptr + sizeof (TYPE);
        }
    }

    template <typename TYPE>
    void operator>> (TYPE& pt)
    {
        if (m_out_ptr)
        {
            (void) memcpy ((char*) &pt, (char*) m_out_ptr, sizeof (TYPE));
            m_out_ptr = (char*) m_out_ptr + sizeof (TYPE);
        }
    }

private:
    void*   m_ptr;
    void*   m_in_ptr;
    void*   m_out_ptr;
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
