
#
# makefile
#

CPP     = ccache g++

# options for compiler
CFLAGS  = -Wall -Werror

# options for (dynamic-link library)
DLFLAGS = -fPIC -shared

# is debug? (for development)
CDEBUG  = -g -D_POOL_EXTEND

# objects
ADDOBJS = handler_add.o
SUBOBJS = handler_sub.o
MULOBJS = handler_mul.o
DIVOBJS = handler_div.o
OBJS    = $(ADDOBJS) $(SUBOBJS) $(MULOBJS) $(DIVOBJS)

# *.so
DLBIN   = libadd.so libsub.so libmul.so libdiv.so

# where are include files kept
INC	    = -I.

# here, go to compiling
all: $(DLBIN)

# how to compiling programs
libadd.so:$(ADDOBJS)
	$(CPP) $(DLFLAGS) $(CFLAGS) $(CDEBUG) -o $@ $(ADDOBJS) 
libsub.so:$(SUBOBJS)
	$(CPP) $(DLFLAGS) $(CFLAGS) $(CDEBUG) -o $@ $(SUBOBJS) 
libmul.so:$(MULOBJS)
	$(CPP) $(DLFLAGS) $(CFLAGS) $(CDEBUG) -o $@ $(MULOBJS) 
libdiv.so:$(DIVOBJS)
	$(CPP) $(DLFLAGS) $(CFLAGS) $(CDEBUG) -o $@ $(DIVOBJS) 

%.o:%.cc
	$(CPP) $(DLFLAGS) $(CFLAGS) $(CDEBUG) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(DLBIN) *~ *.o
