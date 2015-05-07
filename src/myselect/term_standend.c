/* Nicholas Massa
 * term_standend() turns off highlighting
 * Pre: init has been called
 * Post: Highlighting has been turned off
 *
 */

#include "myselect.h"

void term_standend()
{
  tputs(gl_env.stand_end, 1, my_termprint);
}
