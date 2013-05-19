
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
OBJBUFF = test_Buffer.o
OBJMEMZ = test_MemZone.o

# binary
BIN	    = test_Buffer test_MemZone

# where are include files kept
INC	    = -I. -I.. -I../includes -I../handler -I../auth -I../game -I../world -I../login -I../register -I../shared -I../update

# for Linker
LINK    = -lev -lglog -lmysqlcppconn -llua5.2

# here, go to compiling
all: clean $(BIN)

# how to compiling programs
test_Buffer:$(OBJBUFF)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJBUFF) $(LINK)

test_MemZone:$(OBJMEMZ)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJMEMZ) $(LINK)

%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJBUFF) $(OBJMEMZ) $(BIN) *~ logs .lock
