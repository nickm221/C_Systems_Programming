/* Nicholas Massa
 * sendpid sends the client pid to the server
 * Pre: serverpid is a valid process id
 * Post: Client pid is sent to the server
 *
 */

#include "minitalk.h"

void    sendpid(pid_t clipid, pid_t serverpid)
{
	int mask;
	int count;

	mask = 1 << (8 * sizeof(pid_t) - 1);
	for(count = 0; count < (8 * sizeof(pid_t)); count++, clipid <<= 1)
	{
		if(clipid & mask)
		{
			kill(serverpid, SIGUSR1);
		}
		else
		{
			kill(serverpid, SIGUSR2);
		}
		usleep(2000);
	}

}
