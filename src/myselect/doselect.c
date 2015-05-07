/* Nicholas Massa
 * doselect() toggles highlighting for the selected item
 * Pre: There is an item that exists
 * Post: Toggles highlight to the opposite of what it was
 *
 */

#include "myselect.h"

void doselect()
{
  if(gl_env.elements[gl_env.pos].mode == 1)
    gl_env.elements[gl_env.pos].mode = 0;
  
  else
    {
      gl_env.elements[gl_env.pos].mode = 1;
      movedown();
    }
  refreshin();
}
