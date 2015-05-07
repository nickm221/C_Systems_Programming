#include "my.h"

/* Nicholas Massa
 * my_digit() prints the digits 0-9 using the my_int function.
 * pre: Takes no input.
 * post: Prints the digits 0-9.
 *
 */

void my_digits()
{
  unsigned char count;
  for(count = 0; count <= 9; count++)
    my_int(count);
}
