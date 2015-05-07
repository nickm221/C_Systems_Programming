#include "my.h"

/* Nicholas Massa
 * my_strnconcat concatenates the first string with n char of the second string
 * Pre: Takes in 2 strings and a positive integer.  
 * Post: Returns a new string with all of s1 followed by n char of s2
 *
 */


char* my_strnconcat(char* s1, char* s2, unsigned int n)
{
  char* newStr;
  unsigned int newLen;
  unsigned int count;
  unsigned int strPos;

  if (s1 == NULL && s2 == NULL)
    return NULL;

  if (n == 0 || s2 == NULL)
    return my_strdup(s1);

  if (n > my_strlen(s2))
    return my_strconcat(s1, s2);

  if (my_strlen(s1) > 0)
    newLen = my_strlen(s1) + n + 1;
  else
    newLen = n + 1;

  newStr = (char*) xmalloc(newLen * sizeof(char));
  count = newLen - n - 1;
  strPos = 0;

  my_strcat(newStr, s1);

  for( ; s2[strPos] && strPos < n; strPos++, count++)
    newStr[count] = s2[strPos];

  newStr[count] = '\0';

  return newStr;
}
