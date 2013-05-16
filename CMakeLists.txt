
# cmake file for compile card server

cmake_minimum_required (VERSION 2.8)
project (card)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
# is debug?

SET (CMAKE_BUILD_TYPE Debug )

# which c plus plus compiler
#SET (CMAKE_CXX_COMPILER "clang") # apple clang compiler
SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")

# which c compiler
#SET (CMAKE_C_COMPILER "clang")   # apple clang compiler
SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

# directory for includes
INCLUDE_DIRECTORIES (
    ./
    ./includes
    ./handler
)

# source code list
SET (SRC_LIST
    Main.cc
    Config.cc
	RecvTask.cc
   	SendTask.cc
    DataBase.cc
    EventLoop.cc
    Utils.c
    Global.cc
    ThreadPool.cc
    Manager.cc
	handler/Message.cc
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt -lev -lglog -lmysqlcppconn -llua5.2
)

# how to compiling programs
add_executable (card ${SRC_LIST})
target_link_libraries (card ${EXTRA_LIBS})
