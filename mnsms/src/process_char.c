/* 
 * process_char processes a single character, handles inserting in middle & history 
 * Pre: History has been init
 * Post: char c is printed and added to the history
 *
 */

#include "mynotsominishell.h"

void process_char(char c)
{
	int  i;
	char swp;

	if(gl_env.pos == gl_env.count)
	{
		gl_env.history[gl_env.current_history][gl_env.count++] = c;
		gl_env.pos++;
		my_char(c);
	}
	else
	{
		gl_env.history[gl_env.current_history][++gl_env.count] = ' ';

		for(i = gl_env.count; i > gl_env.pos; i--)
		{
			swp = gl_env.history[gl_env.current_history][i];
			gl_env.history[gl_env.current_history][i] = gl_env.history[gl_env.current_history][i - 1];
			gl_env.history[gl_env.current_history][i - 1] = swp;
		}

		rewrite_pos_to_end(gl_env.pos, gl_env.current_history);
		my_char(c);
		gl_env.history[gl_env.current_history][gl_env.pos++] = c;
	}
}