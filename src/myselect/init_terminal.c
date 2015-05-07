/* Nicholas Massa
 * init_terminal() sets up the terminal
 * Pre: None 
 * Post: Sets up terminal for our special uses
 *
 */
#include "myselect.h"


void init_terminal()
{
  struct termio line;
  char*  name;
  int   fd;

  ioctl(0, TCGETA, &line);
  gl_env.line_backup = line;

  line.c_lflag &= ~(ICANON | ECHO | ISIG);
  line.c_cc[VMIN] = READMIN;
  line.c_cc[VTIME] = READTIME;

  ioctl(0, TCSETA, &line);
  
  if(ttyname(0) != NULL )
    name = ttyname(0);
  else
    my_panic("Terminal failed.", 1);
    
  fd = open(name, O_WRONLY);

  gl_env.stdio_backup = dup(1);
  dup2(fd, 1);

  term_vi();
  term_clear();
}
