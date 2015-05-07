/* Nicholas Massa
 * term_vi() turns the cursor off
 * Pre: init is called
 * Post: Cursor is turned off
 *
 */

#include "myselect.h"

void term_vi()
{
  tputs(gl_env.cursoroff, 1, my_termprint);
}
