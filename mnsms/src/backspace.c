/* 
 * backspace removes the character infront of the cursor.
 * Pre: Termcaps init has been called
 * Post: The character before the cursor is removed
 *
 */

#include "mynotsominishell.h"

void backspace()
{
	tputs(gl_env.backspace, 1, my_termprint);
	my_char(' ');
	tputs(gl_env.backspace, 1, my_termprint);
	gl_env.history[0][gl_env.count--] = '\0';
	gl_env.pos--;
}