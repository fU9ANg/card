//
// Singleton
//

#include "Global.h"

Single* Single::p_ = NULL;
Single* Single::instance() 
{
    if (p_ == NULL)
    {
        p_ = new Single(); 
    }
    return p_;
}

Single::Single()
{
}
    
Single::~Single()
{
}
