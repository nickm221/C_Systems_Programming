#include "my.h"

/* Nicholas Massa
 * my_panic prints an error message and exits the program
 * Pre: Takes in a string to print and an int for exit status
 * Post: Prints the string and exits
 *
 */

void my_panic(char* str, unsigned int n)
{
  if(str != NULL)
    my_str(str);
  exit(n);
}
