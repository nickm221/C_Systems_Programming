/* Nicholas Massa
 * moveup() moves the cursor up one term
 * Pre: init has been called
 * Post: The cursor is moved
 *
 */

#include "myselect.h"

void moveup()
{
  refreshout(gl_env.pos);

  if(--gl_env.pos < 0)
    gl_env.pos = gl_env.nbelems - 2;

  refreshin();
}
