/* Nicholas Massa
 * client main for minitalk sends a message to the server via signals
 * Pre: Command Line arguments of serverpid followed by a message to send
 * Post: Client sends message to server or raises SIGALARM if not acknowledged
 *
 */

#define CLIENT_ACTIVE
#include "minitalk.h"

int gl_ack;

int main(int argc, char** argv)
{
	pid_t serverpid;

	gl_ack = 0;

	if(argc < 3)
	  my_panic("Usage: ./client serverpid arg1 [arg2] ...\n",1);
	      

	if((serverpid = my_atoi(argv[1])) <= 0)
		my_panic("Invalid server PID!\n", 1);
	

	signal(SIGUSR1, acknowledge);
	signal(SIGUSR2, nothing);
	signal(SIGALRM, my_alarm);

	sendpid(getpid(), serverpid);

	if(!gl_ack)
	{
	  alarm(2);
         pause();
	}
	alarm(0);

	sendchar(my_vect2str(&argv[2]), serverpid);

	return 0;
}

void nothing()
{
}

void acknowledge()
{
	gl_ack = 1;
}

void my_alarm()
{
	my_panic("Alarm time out. Quitting Program.  \n", 1);
}
