#include "my.h"

/* Nicholas Massa
 * my_strdup returns a pointer to a new duplicated string using xmalloc
 * Pre: Takes a valid string
 * Post: Returns a new pointer to a string with the same contents as the first
 *
 */

char* my_strdup(char* str)
{
  char* newStr = NULL;
  int length = my_strlen(str);

  if(length > -1)
    {
      newStr = (char*) xmalloc(length * sizeof(char) + 1);

      while(*str)
	{
	  *newStr = *str;
	  newStr++;
	  str++;
	}
      *newStr = '\0';
      newStr -= length;
    }

  return newStr;
}
