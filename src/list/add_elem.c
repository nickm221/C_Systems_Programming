#include "mylist.h"

/* Nicholas Massa
 * add_elem creates a new node and adds it to the beginning of the list
 * Pre: Takes an element to add and the head of a list to add to
 * Post: A new node is allocated with an element and added to the front of the list
 *
 */

void add_elem(void* elem, t_node** head)
{
  t_node* newNode;

  if(elem != NULL && head != NULL)
    {
      newNode = new_node(elem, NULL, NULL);
      add_node(newNode, head);
    }
}
