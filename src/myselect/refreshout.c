/* Nicholas Massa
 * refreshout() removes the underline from a term
 * Pre: The position is on the screen
 * Post: The item's underline will be removed when it is reprinted
 *
 */

#include "myselect.h"

void refreshout(int pos)
{
  term_move_to_item(pos);
  if(gl_env.elements[pos].mode)
    {
      term_standout();
    }
  my_str(gl_env.elements[pos].elem);
  term_standend();
  term_underend(); //
}
