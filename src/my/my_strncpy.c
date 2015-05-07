#include "my.h"

/* Nicholas Massa
 * my_strncpy copies first n characters of src to dst
 * Pre: takes a string for a source, a destination, and an unsigned int (num of char to copy)
 * Post: Returns the destination
 *
 */

char* my_strncpy(char* dst, char* src, unsigned int n)
{
  unsigned int count;
  if(dst != NULL && src != NULL && n > 0) 
    {    
      for(count = 0; src[count] && count < n; count++)	  
         dst[count] = src[count];
	
       if(n > my_strlen(src))
         dst[count] = '\0';
    }
 
  return dst;
}
