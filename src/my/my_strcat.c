#include "my.h"

/* Nicholas Massa
 * my_strcat copies s2 at the end of s1
 * Pre: Takes in two strings s1 and s2
 * Post returns s2 at the end of s1
 *
 */

char* my_strcat(char* s1, char* s2)
{
  char* s1Start;

  if(s1 != NULL && s2 != NULL)
    {
      s1Start = s1;
      s1 += my_strlen(s1);
      for( ; *s2; s2++, s1++)
	*s1 = *s2;

      *s1 = '\0';
      s1 = s1Start;
    }
  return s1;
}
