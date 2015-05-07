/* Nicholas Massa
 * term_move_to_item(int) moves the cursor to an item
 * Pre: int is a valid item
 * Post: Moves the cursor to element given by the int
 *
 */

#include "myselect.h"

void term_move_to_item(int pos)
{
  tputs(tgoto(gl_env.move, gl_env.elements[pos].x, gl_env.elements[pos].y), 1, my_termprint);
}
