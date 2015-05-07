#include "my.h"

/* Nicholas Massa
 * my_strlen() calculates the length of the string by counting the number of "characters".
 * Pre: Takes a string.
 * Post: Returns the length of the string.
 *
 */

int my_strlen(char* str)
{
  unsigned int count;
  if(str == NULL)
    {
      return -1;
    }
  count = 0;
  while(*(str+count))
    {
      count++;
    }
  return count;

}
