
#
# makefile for card server
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
OBJS    = 	Card.o \
    		Config.o \
			RecvTask.o \
    		SendTask.o \
		    DataBase.o \
		    EventLoop.o \
		    Utils.o \
		    Global.o \
		    ThreadPool.o \
		    Manager.o \
			handler/Message.o \
			auth/Auth.o \
			login/Login.o \
			register/Register.o \
			update/UpdateFile.o

# binary
BIN	    = card 

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./auth -I./game -I./world -I./login -I./register -I./shared -I./update

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
