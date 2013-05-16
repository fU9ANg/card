
#
# makefile for tester
#

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

# flags of buildhouse
BHFLAGS	= 
#-D_BUILD_HOUSE_GMAE

# is debug? (for development)
CDEBUG  = -g

# macro
CMACRO	= 
#-D_OLD_MAKEHOUSE_GAME

# objects
OBJS    = test_Buffer.o

# binary
BIN	    = test_Buffer 

# where are include files kept
INC	    = -I. -I.. -I../includes -I../handler -I../auth -I../game -I../world -I../login -I../register -I../shared -I../update

# for Linker
LINK    = -lev -lglog -lmysqlcppconn -llua5.2

# here, go to compiling
all: clean $(BIN)

# how to compiling programs
$(BIN):$(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(LINK)
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~ logs .lock
