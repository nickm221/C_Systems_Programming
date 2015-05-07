/* Nicholas Massa
 * moveleft() moves the cursor left one column
 * Pre: init has been called
 * Post: Cursor is moved left one column
 *
 */

#include "myselect.h"

void moveleft()
{
  refreshout(gl_env.pos);

  if((gl_env.pos -= gl_env.win.ws_row) < 0)
    gl_env.pos = 0;

  refreshin();
}
