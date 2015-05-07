#include "my.h"

/* Nicholas Massa
 * my_str prints a string of characters using the my_char function.
 * Pre: Takes an array of characters as input.
 * Post: Prints the array of characters
 *
*/

void my_str(char* str)
{
  if (str != NULL) 
    {
      for (; *str != '\0'; str++)
	{
	  my_char(*str);
	}
    }
}
