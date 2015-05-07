/* Nicholas Massa
 * term_clear() clears the terminal
 * Pre: None
 * Post: The terminal is blank
 *
 */

#include "myselect.h"

void term_clear()
{
  tputs(gl_env.clear, 1, my_termprint);
}
