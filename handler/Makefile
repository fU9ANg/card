
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
OBJS    = main.o
ADDSRCS = handler_add.cc
SUBSRCS = handler_sub.cc
MULSRCS = handler_mul.cc
DIVSRCS = handler_div.cc

# *.so
DLBIN   = libadd.so libsub.so libmul.so libdiv.so

# binary
BIN	    = test_so

# where are include files kept
INC	    = -I.

# for Linker
LINK    = -ldl

# here, go to compiling
all: clean $(BIN) $(DLBIN)

# how to compiling *.so
libadd.so:$(ADDSRCS)
	$(CPP) $(CFLAGS) $(DLFLAGS) $(INC) -o $@ $<
libsub.so:$(SUBSRCS)
	$(CPP) $(CFLAGS) $(DLFLAGS) $(INC) -o $@ $<
libmul.so:$(MULSRCS)
	$(CPP) $(CFLAGS) $(DLFLAGS) $(INC) -o $@ $<
libdiv.so:$(DIVSRCS)
	$(CPP) $(CFLAGS) $(DLFLAGS) $(INC) -o $@ $<

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(LINK)
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) $(DLBIN) *~ *.o
