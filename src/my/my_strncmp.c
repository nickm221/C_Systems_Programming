#include "my.h"

/* Nicholas Massa
 * my_strncmp compare the first n characters of 2 strings.
 * Pre: Takes 2 strings and an integer index to compare up to
 * Post: Returns 0 if strings are equal, Negative if s1 < s2.  Positive is s1 > s2.
 *
 */

int my_strncmp(char* s1, char* s2, unsigned int n)
{
  unsigned int count;

  if((s1 == NULL && s2 == NULL) || (n == 0 && s1 != NULL && s2 != NULL))
    return 0;
  if(s1 == NULL)
    return -1;
  else if(s2 == NULL)
    return 1;

  count = 0;

  while(*s1 && *s2 && (*s1 ==*s2) && count < n-1)
    {
      count++;
      s1++;
      s2++;
    }
  return *s1 - *s2;
}
