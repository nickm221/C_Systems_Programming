/* Nicholas Massa
 * setup_elems(int, char**) sets up the elements
 * Pre: An element exists
 * Post: The elements are set up
 *
 */

#include "myselect.h"

void setup_elems(int num_elems, char** elements)
{
  int i = 0;
  gl_env.nbelems = num_elems;
  gl_env.elements = (t_elem *) xmalloc(num_elems * sizeof(t_elem));

  for(i = 0; i < num_elems; i++)
    {
      gl_env.elements[i].elem = elements[i];
      gl_env.elements[i].size = my_strlen(elements[i]);
      gl_env.elements[i].mode = 0;
      gl_env.elements[i].x = 0;
      gl_env.elements[i].y = 0;
    }
}
