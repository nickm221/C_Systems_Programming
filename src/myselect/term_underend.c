/* Nicholas Massa
 * term_underend() turns underlining off
 * Pre: Init has been called
 * Post: Underlining is turned off
 *
 */

#include "myselect.h"

void term_underend()
{
  tputs(gl_env.under_end, 1, my_termprint);
}
