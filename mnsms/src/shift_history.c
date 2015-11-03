/*
 * shift_history shifts the hisory up by 1
 * Pre: History is initialized
 * Post: History is shifted up by 1 index
 *
 */

#include "mynotsominishell.h"

void shift_history()
{
	char* swp;
	int   i;

	for(i = 0; i < HISTORY_SIZE - 1; i++)
	{
		swp = gl_env.history[i];
		gl_env.history[i] = gl_env.history[i + 1];
		gl_env.history[i + 1] = swp;
	}

	gl_env.history[HISTORY_SIZE - 1][0] = '\0';
}