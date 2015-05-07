#include "my.h"

/* Nicholas Massa
 * my_strfind finds a character and returns a pointer to the first occurence of that char
 * Pre: Takes a string and a char to locate
 * Post: Returns a pointer to the character
 *
 */

char* my_strfind(char* str, char c)
{
  if(str != NULL && c != '\0')
    {
      for( ; *str; str++)
	if(*str == c)
	  return str;
    }
  return NULL;

}
