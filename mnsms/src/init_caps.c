/*
 * init_caps() initializes all termcaps 
 * Pre: None
 * Post: termcaps in gl_env are set up
 *
 */
 
#include "mynotsominishell.h"

void init_caps()
{
	char* term;
	char  bp[2048];

	term = getenv("TERM");
	tgetent(bp, term);

	gl_env.left = term_get_cap(LEFT);
	gl_env.right = term_get_cap(RIGHT);
	gl_env.up = term_get_cap(UP);
	gl_env.down = term_get_cap(DOWN);
	gl_env.backspace = term_get_cap(BACKSPACE);
	gl_env.move_right = term_get_cap(MOVE_RIGHT);
	gl_env.clear = term_get_cap(CLEAR);
}