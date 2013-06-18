
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iostream>
#include "handler.hpp"

using namespace std;
#if 1
int main ()
{
    CHandlers handlers;

    handlers.init_handle ();
    handlefunc hf;
    hf = handlers.get_handle (1);
    cout << "result of add = " << hf (20, 10) << endl;
    hf = handlers.get_handle (2);
    cout << "result of sub = " << hf (20, 10) << endl;
    hf = handlers.get_handle (3);
    cout << "result of mul = " << hf (20, 10) << endl;
    hf = handlers.get_handle (4);
    cout << "result of div = " << hf (20, 10) << endl;
}
#else
int main ()
{
    void* dl_handle;
    int (*func_handle) (int, int);
    char* error;

    dl_handle = dlopen ("./libtest.so", RTLD_LAZY);
    if (dl_handle == NULL) {
        fprintf (stderr, "%s ", dlerror ());
        exit (1);
    }

    *(void **) (&func_handle) = dlsym (dl_handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "error: %s \n", error);
        exit (1);
    }
    printf ("add = %d\n", (*func_handle) (20, 10));

    *(void **) (&func_handle) = dlsym (dl_handle, "sub");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "error: %s \n", error);
        exit (1);
    }
    printf ("sub = %d\n", (*func_handle) (20, 10));

    dlclose (dl_handle);

    return (0);
}
#endif
