/* Nicholas Massa
 * serv_kill() stops the child process
 * Pre: None
 * Post: Stops the child process
 *
 */

#include "sockets.h"

extern struct s_gl_env gl_env;

void stop_server()
{
	usleep(getpid());
	close(gl_env.sockfd);
	exit(0);
}
