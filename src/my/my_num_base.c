#include "my.h"

/* Nicholas Massa
 * my_num_base() prints a number in another base determined by the length of a string.
 * Pre: Takes an integer and an array of characters as input
 * Post: Prints the number in a base represented by the character indices.
 *
 */

void my_num_base(int num, char* str)
{
  int base;
  unsigned int posnum;
  unsigned int count;
  unsigned int power;
  power = 1;
  base = my_strlen(str);

  if (str != NULL && base != 0)
    {
      if(num < 0)
	{
	  my_char('-');
	  posnum = num*-1;
	}
      else
	posnum = num;

      if(base == 1) /* For the case of base 1, print the char as many times as the number. */
	  for(count = 0; count < posnum; count++)
	    my_char(str[0]);
      else /* If base is not 1. */
	{
	  /* Calculate the power from the base. */
	  for( ; power <= (posnum / base); power *= base);
	  
	  do 
	    {
	      my_char(str[posnum / power]); 
	      posnum %= power;
	      power /= base;
	    } while(power);
	}
    }
  else 
    my_str("Base not valid");
}

