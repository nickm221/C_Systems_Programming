/* Nicholas Massa
 * term_underline() underline is on
 * Pre: init has ben called
 * Post: Underline is on
 *
 */

#include "myselect.h"

void term_underline()
{
  tputs(gl_env.underline, 1, my_termprint);
}
