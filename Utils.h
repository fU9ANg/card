
#ifndef _CARDSRV_UTILS_H_
#define _CARDSRV_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#ifdef __cplusplus
extern "C"{
#endif

extern ssize_t send_n (int fd, void* buf, ssize_t left, struct timeval* timeout);
extern int     send_v (int fd, void* buf, ssize_t left);

extern ssize_t recv_n (int fd, void* buf, ssize_t left, struct timeval* timeout);
extern int     recv_v (int fd, void* buf, ssize_t left);

#ifdef __cplusplus
}
#endif

#endif //_CARDSRV_UTILS_H_
