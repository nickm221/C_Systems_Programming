/* Ashley Bromiley Nicholas Massa
 * main for running the terminal
 * Pre: Takes the number of args and the args
 * Post: Terminal is ran
 *
 */

#include "mynotsominishell.h"

int main(int argc, char** argv)
{
	char   buffer[BUFFER_SIZE];
	char** args;
	int    bytes;
	int    i;
	int    history_done;

	init_terminal();
	init_caps();

	gl_env.history = (char**) xmalloc(HISTORY_SIZE * sizeof(char*));
	for(i = 0; i < HISTORY_SIZE; i++)
	{
		gl_env.history[i] = (char*) xmalloc(BUFFER_SIZE * sizeof(char));
	}

	history_done = 1;

	while(1)
	{
		if(history_done)
		{
			gl_env.history[gl_env.current_history][0] = '\0';
	    	gl_env.dir = getcwd(gl_env.dir, BUFFER_SIZE);
			my_str(gl_env.dir);
	    	my_str(": ");
	    	history_done = 0;
	    	gl_env.count = 0;
	    	gl_env.pos = 0;
	    }

		if((bytes = read(0, buffer, BUFFER_SIZE - 1)) < 0)
		{
			my_str("Read failed\n");
			exit(0);
		}

		buffer[bytes] = '\0';

		if(buffer[0] == '\n')
		{
			my_char('\n');
			gl_env.history[gl_env.current_history][gl_env.count] = '\0';
			args = my_str2vect(gl_env.history[gl_env.current_history]);
			process_input(args);
			if(my_strcmp(gl_env.history[gl_env.current_history], "") != 0)
			{
				shift_history();
			}
			history_done = 1;
		}
		else if(buffer[0] == 0x7f)
		{
			if(gl_env.pos > 0)
			{
				backspace();
			}
		}
		else
		{
			if(!do_cap(buffer))
			{
				process_char(buffer[0]);
			}
		}
	}

	return 0;
}
