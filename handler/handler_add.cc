
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif

int add (int x, int y)
{
    return (x + y);
}

#ifdef __cplusplus
}
#endif
