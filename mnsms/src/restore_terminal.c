/* 
 * restore_terminal restores the terminal to its original state
 * Pre: Terminal has been modified
 * Post: Terminal is restored
 *
 */
 
 #include "mynotsominishell.h"

void restore_terminal()
{
	ioctl(0, TCSETA, &(gl_env.line_backup));
	dup2(gl_env.stdio_backup, 1);
}