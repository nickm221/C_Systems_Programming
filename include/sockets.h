/*
 * sockets.h
 *
 * Communication between a server and several clients
 * using sockets
 *
 * Author: Jason Ajmo (jajmo@stevens.edu)
 * Last Modified: 10/30/14 11:47 PM
 */

#ifndef _SOCKETS_H_
#define _SOCKETS_H_
#define BUFFER_SIZE 512

#include "my.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>
#include <netdb.h>


int sockfd;

struct s_gl_env
{
  int sockfd;
  char* username;
  int pid;
} gl_env;

/* #ifdef SERVER_INC*/
int main(int, char**);
void diecli();
void disconnect();
int main(int, char**);
void bye();
void stop_server();

#endif
