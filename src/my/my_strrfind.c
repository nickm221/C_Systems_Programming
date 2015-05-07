#include "my.h"

/* Nicholas Massa
 * my_strrfind finds the last occurence of a character in a string
 * Pre: Takes a string and a character to find within that string
 * Post: Returns a pointer to the location of the last occurence of that char
 *
 */

char* my_strrfind(char* str, char c)
{
  char* last = NULL;

  if(str != NULL && c != '\0')
    {
      for( ; *str; str++)
	if(*str == c)
	  last = str;

      str = last;

    }
  return str;
}
