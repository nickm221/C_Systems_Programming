/* Nicholas Massa
 * sockets.h is the header file for the sockets project.
 *
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

int sockfd;

struct s_gl_env
{
	int sockfd;
	char* username;
	int pid;
} gl_env;

void disconnect();

#ifdef SERVER_INC
 	void bye();
 	void stop_server();
#else
        #include <netdb.h>
#endif
#endif
