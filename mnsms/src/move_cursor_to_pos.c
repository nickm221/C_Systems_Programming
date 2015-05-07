/*
 * move_cursor_to_pos() moves the cursor to the given pos
 * Pre: Takes a valid int
 * Post: Moves the cursor to position pos
 *
 */

#include "mynotsominishell.h"

void move_cursor_to_pos(int pos)
{
	if(gl_env.pos < pos)
	{
		while(gl_env.pos++ < pos)
		{
			tputs(gl_env.move_right, 1, my_termprint);
		}
		gl_env.pos--;
	}
	else
	{
		while(gl_env.pos-- > pos)
		{
			tputs(gl_env.backspace, 1, my_termprint);
		}
		gl_env.pos++;
	}
}