/* Nicholas Massa
 * my_termprint() writes a character to the terminal
 * Pre: Takes in the char to write 
 * Post: Writes the char to the screen
 *
 */

#include "myselect.h"

int my_termprint(int c)
{
  return write(1, &c, 1);
}
