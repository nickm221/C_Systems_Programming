/* Nicholas Massa
 * getmessage takes in a signal to determine if the bit is 1 or 0, and prints a character 
 * Pre: Takes in the signal
 * Post: Every 8 bits recieved, a character is printed
 *
 */

#include "minitalk.h"

void getchar(int sig)
{
	static char current = 0;
	static int counter = 0;

	current <<= 1;

	if(sig == SIGUSR1)
	{
		current |= 1;
	}

	if(++counter >= 8)
	{
		if(current == '\0')
		{
			gl_env.done = 1;
			kill(gl_env.clipid, SIGUSR1);
		}
		else
		{
			my_char(current);
		}
		current = 0;
		counter = 0;
	}

	kill(gl_env.clipid, SIGUSR2);
}
