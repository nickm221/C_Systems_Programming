#include "my.h"

/* Nicholas Massa
 * my_int() prints an integer by repeatedly using the my_char function.
 * Pre: Takes an integer as input.
 * Post: Prints the integer.
 *
*/

void my_int(int num)
{
  unsigned int posNum;
  unsigned int power;

  if(num < 0)
    {
      my_char('-');
      posNum = num * -1;
    }
  else
      posNum = num;

  for(power = 1; power <= (posNum / 10); power *= 10); /* Find where to start from the left*/
    
  do 
    {
      my_char('0' +  (posNum / power)); /* use the character 0 so that posNum prints as char*/
      posNum %= power;
      power /= 10;
    } while(power);
}
