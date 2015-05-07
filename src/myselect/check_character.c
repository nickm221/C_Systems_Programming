/* Nicholas Massa
 * check_character(char*) Processes character input
 * Pre: Takes a character
 * Post: Processes keyboard input
 *
 */

#include "myselect.h"

void check_character(char* c)
{
  if(c != NULL)
    {
      if(!my_strcmp(c, KU))
	moveup();

      else if(!my_strcmp(c, KD))
	movedown();

      else if(!my_strcmp(c, KL))
	moveleft();
	
      else if(!my_strcmp(c, KR))
	moveright();
       
      else if(!my_strcmp(c, " "))
	doselect();
	
      else
	getout(c);
    }
}
