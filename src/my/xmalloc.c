#include "my.h"

/* Nicholas Massa
 * xmalloc calls malloc and performs all necessary checks.
 * Pre: Takes an integer to pass to malloc
 * Post: Allocates the specified amount of memory in the heap
 *
 */

void *xmalloc(unsigned int n)
{
  void *p = NULL;
  if(!(p = malloc(n)))
    {
      my_str("Virtual Memory Exhausted \n");
      exit(1);
    }
  return p;
}
