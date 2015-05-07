/* Nicholas Massa
 * Getout(char*) exits the program
 * Pre: Valid Character is input 
 * Post: Exits the program
 *
 */

#include "myselect.h"


void getout(char* input)
{
  int count;

  if(input != NULL)
    {
      if(!my_strcmp(input, "\n"))
	{
	  restore_terminal();
	  for(count = 0; count < gl_env.nbelems; count++)
	    {
	      if(gl_env.elements[count].mode)
		{
		  my_str(gl_env.elements[count].elem);
		  my_str(" ");
		}
	    }
	  my_char('\n');
	  exit(0);
	}
      else if(!my_strcmp(input, "\E"))
	{
	  restore_terminal();
	  exit(0);
	}
    }
}
