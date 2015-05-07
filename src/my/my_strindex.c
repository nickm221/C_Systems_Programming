#include "my.h"

/* Nicholas Massa
 * my_strindex Finds the first occurence of a character in the provided string.
 * pre: Takes in a string and the character that you wish to locate within that string
 * post: Returns the index of the char starting with the first char of the string as
 * index 0.  Returns -1 if not found.
 *
 */

int my_strindex(char* str, char c)
{
  unsigned int count;
  if(str != NULL)
    {
      count = 0;
      while(str[count])
	{
	  if(str[count] == c)
	    return count;
	  count++;
	}
    }
  return -1;
}
