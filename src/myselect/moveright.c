/* Nicholas Massa
 * moveright() moves the cursor right one column
 * Pre: init has been called
 * Post: moves the cursor right one column
 *
 */

#include "myselect.h"

void moveright()
{
  refreshout(gl_env.pos);
  
  if((gl_env.pos += gl_env.win.ws_row) >= gl_env.nbelems - 1)
    gl_env.pos = gl_env.nbelems - 2;
  
  refreshin();
}
