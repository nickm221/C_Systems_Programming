/* Nicholas Massa
 * restore_terminal() restores the terminal to its original settings
 * Pre: Terminal settings already modified
 * Post: Restores terminal settings
 *
 */

#include "myselect.h"

void restore_terminal()
{
  dup2(gl_env.stdio_backup, 1);
  term_clear();
  ioctl(0, TCSETA, &(gl_env.line_backup));
  term_ve();
}
