/* 
 * rewrite_pos_to_end position writes an item in history from pos to eow
 * Pre: History has been initialized.  pos < gl_env.count
 * Post: The line is rewritten
 *
 */

#include "mynotsominishell.h"

void rewrite_pos_to_end(int pos, int history_num)
{
	int pos_backup;

	pos_backup = pos;

	while(pos_backup++ < gl_env.count)
	{
		tputs(gl_env.move_right, 1, my_termprint);
	}

	while(pos_backup-- > pos + 1)
	{
		tputs(gl_env.backspace, 1, my_termprint);
		my_char(' ');
		tputs(gl_env.backspace, 1, my_termprint);
	}

	while(pos_backup++ < gl_env.count)
	{
		my_char(gl_env.history[history_num][pos_backup - 1]);
	}

	while(pos_backup-- > pos + 1)
	{
		tputs(gl_env.backspace, 1, my_termprint);
	}
}