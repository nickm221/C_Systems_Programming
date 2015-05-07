#include "my.h"

/* Nicholas Massa
 * my_char prints a single character.
 * pre: Takes a char as input.
 * post: Prints the char.
 * 
*/

void my_char(char c)
{
  write(1, &c, 1); /* 1: std out to screen, address, size */
}
