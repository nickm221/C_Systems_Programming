/* Nicholas Massa
 * getclientpid updates the client pid with a 1 or 0 based on the signal recieved
 * Pre: Takes in a signal (0 or 1)
 * Post: Updates the clientpid
 *
 */

#include "minitalk.h"

void getclientpid(int sig)
{
	gl_env.clipid <<= 1;

	if(sig == SIGUSR1)
	{
		gl_env.clipid |= 1;
	}
}
