/*
 * init_terminal() initializes the terminal preparing it for execution 
 * Pre: None
 * Post: Terminal is initialized with special settings
 *
 */

#include "mynotsominishell.h"

void init_terminal()
{
	struct termio modify;
	char* name;
	int fd;

	ioctl(0, TCGETA, &(gl_env.line_backup));
	modify = gl_env.line_backup;

	modify.c_lflag &= ~(ICANON | ECHO | ISIG);

	ioctl(0, TCSETA, &modify);

	name = ttyname(0);
	fd = open(name, O_WRONLY);

	gl_env.stdio_backup = dup(1);
	dup2(fd, 1);

	ioctl(0, TIOCGWINSZ, &(gl_env.win));

	gl_env.current_history = HISTORY_SIZE - 1;
}