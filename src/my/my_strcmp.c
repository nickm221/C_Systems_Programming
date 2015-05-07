#include "my.h"

/* Nicholas Massa
 * my_strcmp compares 2 strings.  neg if s1 < s2.  0 if equal.  Positive if s1 > s2.  
 * Pre: Takes in two strings to compare.
 * Post: The comparison value is returned (Negative, 0, Positive)
 *
 */

int my_strcmp(char* s1, char* s2)
{
  if(s1 == NULL && s2 == NULL)
    return 0;
  if(s1 == NULL)
    return -1;
  else if(s2 == NULL)
    return 1;

  while(*s1 && *s2 && (*s1 == *s2))
    {
      s1++;
      s2++;
    }
  return *s1 - *s2;
}
