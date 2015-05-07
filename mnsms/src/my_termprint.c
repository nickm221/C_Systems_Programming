/* 
 * my_termprint writes a character to the terminal
 * Pre: None
 * Post: c is written to the terminal
 *
 */

#include "mynotsominishell.h"

int my_termprint(int c)
{
	return write(1, &c, 1);
}