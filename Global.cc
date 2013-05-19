//
// singleton
//

#include "Global.h"

Global* Global::p_ = NULL;
Global* Global::instance() 
{
    if (p_ == NULL)
    {
        p_ = new Global(); 
    }
    return p_;
}

Global::Global()
{
}
    
Global::~Global()
{
}
