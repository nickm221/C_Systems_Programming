
/* Nicholas Massa
 * minishell is a version of command line with basic shell functionality, 
 * using fork(), aswell as cd and exit.
 * Pre: None.  Takes input as text while running.  
 * Post: The shell is opened and running
 *
 */

#include "my.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 512
#endif

 
int main(int argc, char** argv)
{
	char   buffer[BUFFER_SIZE];
	char** args;
	int    status;
	int    bytes;
	int    pid;

	my_str("Welcome to Nick's shell: \n");

	while(1)
	{
		
    	my_str("> ");

		if((bytes = read(0, buffer, BUFFER_SIZE - 1)) < 0)
		{
			my_panic("Invalid read\n", 1);
		}

		buffer[bytes - 1] = '\0';

		args = my_str2vect(buffer);

		if(my_strcmp(args[0], "cd") == 0)
		{
			if((status = chdir(args[1])) < 0)
			{
				if(args[1] == NULL)
				{
					my_str("Invalid arguments\n");
				}
				else
				{
					my_str(args[1]);
					my_str(": Directory not found\n");
				}
			}
		}
		else if(my_strcmp(args[0], "exit") == 0)
		{
			my_panic("Congrats on no fork bombs! \n", 0);
        	}
		else
		{
			if((pid = fork()) < 0)
				my_panic("fork() error!\n", 1);

			if(pid > 0)
				wait();
			
			else
			{
				if((status = execvp(args[0], args)) < 0)
				{
					my_str(args[0]);
					my_str(": Command not found!\n");
				}
			exit(0);
			}
		}
	}

	return 0;
}
