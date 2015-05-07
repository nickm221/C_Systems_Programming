/* Nicholas Massa
 * movedow() moves the cursor down one term
 * Pre: init has been called
 * Post: The cursor is moved down one term
 *
 */

#include "myselect.h"

void movedown()
{
  refreshout(gl_env.pos);

  if(++gl_env.pos > gl_env.nbelems - 2)
    gl_env.pos = 0;

  refreshin();
}
