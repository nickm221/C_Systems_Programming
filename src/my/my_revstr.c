#include "my.h"

/* Nicholas Massa
 * my_revstr reverses a string starting from the ends and working towards the middle.
 * pre: Takes a string to reverse.  
 * post: Reverses the string and returns the length of the string.
 *
*/

int my_revstr(char* str)
{
  int length;
  int front;
  int end;
  char temp;

  length = my_strlen(str);
  front = 0;
  end = length - 1; /* Last Char */

  if(str != NULL && length > 0)
    {
      for ( ; front < end; front++, end--) 
	{
	  temp = str[front];
	  str[front] = str[end];
	  str[end] = temp;
	}
      return length;
    }
  return -1;
}
