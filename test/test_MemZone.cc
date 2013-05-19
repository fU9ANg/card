
#include "Buffer.h"
#include "MemZone.h"

MemZone <Buffer > bufpool;

int main (int argc, char** argv)
{
    Buffer* buffer;
    int int1 = 100;
    int int2 = 200;
    int int3, int4;

    while (1)
    {
        if ((buffer = bufpool.malloc ()) != NULL)
        {
            cout << "size of memzone: " << bufpool.size () << endl;
            (*buffer) << int1;
            (*buffer) << int2;
            (*buffer) >> int3;
            (*buffer) >> int4;

            cout << "int3=" << int3 << endl;
            cout << "int4=" << int4 << endl;
            cout << "free buffer to memzone" << endl;
            bufpool.free (buffer);
        }
        else
        {
            cout << "no space in the system" << endl;
            return (1);
        }
    }

    return (0);
}
