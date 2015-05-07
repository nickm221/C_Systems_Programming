/* Nicholas Massa
 * refreshin() displays an item with an underline.
 * Pre: Terminal is initialized
 * Post: The item is shown with an underline
 *
 */

#include "myselect.h"

void refreshin()
{
  term_move_to_item(gl_env.pos);
  term_underline();
  if(gl_env.elements[gl_env.pos].mode)
    term_standout();

  my_str(gl_env.elements[gl_env.pos].elem);
  term_standend();
  term_underend();
}
