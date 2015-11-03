/*
 * history_up() moves up one spot in the history 
 * Pre: History initialized
 * Post: History moves up one index and is printed
 *
 */
 
#include "mynotsominishell.h"
 
 void history_up()
{
	clear_input();
	gl_env.count = my_strlen(gl_env.history[--gl_env.current_history]);
	gl_env.pos = 0;
	rewrite_pos_to_end(0, gl_env.current_history);
	move_cursor_to_pos(gl_env.count);
}