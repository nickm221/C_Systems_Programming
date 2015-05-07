#include "my.h"

/* Nicholas Massa
 * my_alpha() prints the characters a-z using the my_char function.
 * Pre: Takes no input
 * Post: Prints out all characters a-z.
 *
 */

void my_alpha()
{
  unsigned char count;
  for(count = 'a'; count <='z'; count++)
    my_char(count);
}
