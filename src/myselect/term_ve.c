/* Nicholas Massa
 * term_ve() turns the cursor on
 * Pre: init has been called
 * Post: turns the cursor on
 *
 */

#include "myselect.h"

void term_ve()
{
  tputs(gl_env.cursoron, 1, my_termprint);
}
