

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <dlfcn.h>
#include <map>

using namespace std;

typedef int (*handlefunc) (int, int);

class CHandlers
{
    private:
        typedef std::map<int, handlefunc> HANDLEMAP;
        typedef std::map<void*, string>   DLFILEMAP;

    public:
        CHandlers ()
        {
            // TODO:
        }
        ~CHandlers ()
        {
            destory_dl_handle ();
        }

        void destory_dl_handle ()
        {
            DLFILEMAP::iterator it;
            for (it = m_dlfile_map.begin(); it != m_dlfile_map.end(); ++it)
            {
                if (it->first)
                    dlclose (it->first);
                m_dlfile_map.erase (it);
            }
        }

        void init_handle (void)
        {
            void* dl_handle;
            handlefunc hf;
            char* error;

            // Add
            dl_handle = dlopen ("./so/libadd.so", RTLD_LAZY);
            if (dl_handle == NULL) {
                fprintf (stderr, "%s ", dlerror ());
                exit (1);
            }

            *(void **) (&hf) = dlsym (dl_handle, "add");
            if ((error = dlerror()) != NULL) {
                fprintf (stderr, "error: %s \n", error);
                exit (1);
            }
            set_handle (1, hf);
            m_dlfile_map.insert (pair<void*, string> (dl_handle, "libadd.so"));

            // Sub
            dl_handle = dlopen ("./so/libsub.so", RTLD_LAZY);
            if (dl_handle == NULL) {
                fprintf (stderr, "%s ", dlerror ());
                exit (1);
            }

            *(void **) (&hf) = dlsym (dl_handle, "sub");
            if ((error = dlerror()) != NULL) {
                fprintf (stderr, "error: %s \n", error);
                exit (1);
            }
            set_handle (2, hf);
            m_dlfile_map.insert (pair<void*, string> (dl_handle, "libsub.so"));

            // Mul
            dl_handle = dlopen ("./so/libmul.so", RTLD_LAZY);
            if (dl_handle == NULL) {
                fprintf (stderr, "%s ", dlerror ());
                exit (1);
            }

            *(void **) (&hf) = dlsym (dl_handle, "mul");
            if ((error = dlerror()) != NULL) {
                fprintf (stderr, "error: %s \n", error);
                exit (1);
            }
            set_handle (3, hf);
            m_dlfile_map.insert (pair<void*, string> (dl_handle, "libmul.so"));

            // DIV
            dl_handle = dlopen ("./so/libdiv.so", RTLD_LAZY);
            if (dl_handle == NULL) {
                fprintf (stderr, "%s ", dlerror ());
                exit (1);
            }

            *(void **) (&hf) = dlsym (dl_handle, "divi");
            if ((error = dlerror()) != NULL) {
                fprintf (stderr, "error: %s \n", error);
                exit (1);
            }
            set_handle (4, hf); 
            m_dlfile_map.insert (pair<void*, string> (dl_handle, "libdiv.so"));
        }

        void set_handle (int type, handlefunc hFunc)
        {
            if (hFunc)
                m_handle_map.insert (std::pair<int, handlefunc> (type, hFunc));
        }

        handlefunc get_handle (int type)
        {
            HANDLEMAP::iterator it;
            it = m_handle_map.find (type);
            if (it != m_handle_map.end ())
                return (it->second);

            return (NULL); 
        }

    private:
        HANDLEMAP m_handle_map;
        DLFILEMAP m_dlfile_map;
};
