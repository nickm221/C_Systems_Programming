#include "sockets.h"

/* Nicholas Massa
 * bye.c kills client connection
 * Pre: None
 * Post: Server shuts down
 *
 */

extern struct s_gl_env gl_env;

void bye()
{
	usleep(40 * getpid());
	my_str("***");
	my_str(gl_env.username);
	my_str(" disconnected\n");
	usleep(100 * getpid());
	exit(0);
}
