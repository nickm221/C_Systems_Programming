/* Nicholas Massa 
 * Term_get_cap(char*) takes a termcap and returns it as a char*
 * Pre: Takes a valid cap
 * Post: Returns the termcap as a string
 *
 */

#include "myselect.h"

char* term_get_cap(char* cap)
{
  char* str;
  char area[2048];

  if((str = tgetstr(cap, (char**) & area)) == NULL)
    my_panic("Cap not valid.", 1);

  return str;
}
