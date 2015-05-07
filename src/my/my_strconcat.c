#include "my.h"

/* Nicholas Massa
 * my_strconcat returns a new string containing s1 followed by s2
 * Pre: Takes in 2 strings to concatenate
 * Post: Returns a new string containing the 2 strings 
 *
 */

char* my_strconcat(char* s1, char* s2)
{
  char* newStr;
  unsigned int newLength;

  if(s1 == NULL && s2 == NULL)
    return NULL;

  if(s1 == NULL)
    return my_strdup(s2);
  
  if(s2 == NULL)
    return my_strdup(s1);

  newLength = my_strlen(s1) + my_strlen(s2) + 1;
  newStr = (char*) xmalloc(newLength * sizeof(char));

  my_strcpy(newStr, s1);
  my_strcat(newStr, s2);

  return newStr;
}
