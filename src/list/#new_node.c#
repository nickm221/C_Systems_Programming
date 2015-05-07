#include "mylist.h"

/* Nicholas Massa
 * new_node creates a new node for the linked list
 * Pre: Takes in a non-null element and a next and previous pointer
 * Post: The new node is allocated.  Returns a pointer to the new node
 *
 */

t_node *new_node(void* e, t_node *n, t_node *p)
{
  t_node* newNode = NULL;
  /*  if(e != NULL)*/
    {
      newNode = (t_node*) xmalloc(sizeof(t_node));
      newNode->elem = e;
      newNode->next = n;
      newNode->prev = p;
    }
  return newNode;
}
