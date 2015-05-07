/* Nicholas Massa
 * term_standout() turns on highlighting
 * Pre: Init has been called
 * Post: Highlighting is turned on
 *
 */

#include "myselect.h"

void term_standout()
{
  tputs(gl_env.standout, 1, my_termprint);
}
