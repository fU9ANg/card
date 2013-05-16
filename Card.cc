
#include <stdio.h>
#include "ThreadPool.h"
#include "Atomic.h"
#include "MemZone.h"
#include "Buffer.h"

#include "Manager.h"

int main (int argc, char* argv[])
{
    manager* process = NULL;

    if ((process = new manager ()) == NULL)
    {
        cout << "ERROR: manager is NULL" << endl;
        abort ();
    }

    process->execute (argc, argv);

    delete process;
    return (0);
}
