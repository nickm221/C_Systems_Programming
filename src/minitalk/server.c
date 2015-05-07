/* Nicholas Massa
 * Server main responsible for reading in a message and printing it via getmessage
 * Pre: Takes no arguments
 * Post: Prints the recieved message and waits to receive the next message
 *
 */

#define SERVER_ACTIVE
#include "minitalk.h"

struct  s_env gl_env;

int main()
{
	int count;

	signal(SIGINT, my_goodbye);

	my_str("Server PID: ");
	my_int(getpid());
	my_str("\n\n");

	while(1)
	{
		gl_env.clipid = 0;
		gl_env.done   = 0;

		signal(SIGUSR1, getclientpid);
		signal(SIGUSR2, getclientpid);

		for(count = 0; count < (8 * sizeof(pid_t)); count++)
		{
			pause();
		}

		signal(SIGUSR1, getchar);
		signal(SIGUSR2, getchar);

		kill(gl_env.clipid, SIGUSR1);

		while(!gl_env.done)
			pause();
		
		my_str("\n\n");
	}

	return 0;
}

void my_goodbye()
{
	my_panic("\nServer: Goodbye!\n", 0);
}
