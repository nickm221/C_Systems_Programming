/*
 * process_input processes a command
 * Pre: arg is not null
 * Post: command is ran, or err msg printed
 *
 */

#include "mynotsominishell.h"

void process_input(char** args)
{
	int pid;
	int status;

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
		my_str("No fork bombs? Good! Have a great day :)\n");
       		restore_terminal();
		exit(0);
	}
	else
	{
		if((pid = fork()) < 0)
		{
			my_str("fork() critical error!\n");
			exit(0);
		}

		if(pid > 0)
		{
			wait();
		}
		else
		{
			if((status = execvp(args[0], args)) < 0)
			{
				my_str(args[0]);
				my_str(": Command not found!\n");
				exit(0);
			}
		}
	}
}
