#include "my.h"

/* Nicholas Massa
 * my_strcpy copies src to dst overwriting dst
 * Pre: Takes in the string to be copied 
 * Post: Returns the destination
 *
 */

char* my_strcpy(char* dst, char* src)
{
  char* dstStart;

  if(dst != NULL && src != NULL)
    {
      dstStart = dst;

      while(*src)
	{
	  *dst = *src;
	  src++;
	  dst++;
	}
      *dst = '\0';
      dst = dstStart;
    }
  return dst;
}
