/* Nicholas Massa
 * sendchar sends the mmessage to the server via signals
 * Pre: Takes in the message and a pid to send the message to
 * Post: The message is sent
 *
 */

#include "minitalk.h"

void sendchar(char* message, pid_t serverpid)
{
	char mask;
	char count;

    if(message != NULL)
    {
        mask = 0x80;
        gl_ack = 0;
        count = 0;
        while(!gl_ack)
        {
            if(*message & mask)
                kill(serverpid, SIGUSR1);
            
            else
                kill(serverpid, SIGUSR2);
            

            if(++count == 8)
            {
                message++;
                count = 0;
            }
            else
                *message <<= 1;
            
            pause();
        }
    }
}
