#ifndef _MINITALK_H_
#define _MINITALK_H_

#include "my.h"
#include <signal.h>

struct s_env
{
	int clipid;
	char done;
} gl_env;

int gl_ack;

#ifdef SERVER_ACTIVE

void getclientpid(int);
void getchar(int);
void my_goodbye();

#else

void my_alarm();
void acknowledge();
void nothing();
void sendchar(char*, pid_t);
void sendpid(pid_t, pid_t);

#endif
#endif
