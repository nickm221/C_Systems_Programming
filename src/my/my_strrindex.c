#include "my.h"

/* Nicholas Massa
 * my_strrindex() finds the last occurence of a character in a given string.
 * Pre: Takes in an array of characters and a character to find the last occurence of.
 * Post: Returns the index of the last occurence of the character in the string.
 *
 */

int my_strrindex(char* str, char c) 
{
    unsigned int current;
    unsigned int last;
    last = -1;
    current = 0;

  if (str != NULL)
    {
      while(str[current])
	{
	  if (str[current] == c)
	    last = current;
	  current++;
	}
      return last;
    }
  return -1;
}
