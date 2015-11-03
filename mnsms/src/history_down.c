/*
 * history_down() moves down one spot in the history 
 * Pre: History initialized
 * Post: History moves down one index and is printed
 *
 */

#include "mynotsominishell.h"

void history_down()
{
	clear_input();
	gl_env.count = my_strlen(gl_env.history[++gl_env.current_history]);
	gl_env.pos = 0;
	rewrite_pos_to_end(0, gl_env.current_history);
	move_cursor_to_pos(gl_env.count);
}