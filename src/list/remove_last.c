#include "mylist.h"

/* Nicholas Massa
 * remove_last removes the last node from the list
 * Pre: The list contains atleast one element
 * Post: Removes the last node and returns a pointer to the element within
 *
 */

void* remove_last(t_node** head)
{
  t_node* nextNode;
  void* nodeElem;

  if(head != NULL && *head != NULL)
    {
      nextNode = *head;

      while(nextNode->next->next != NULL)
	nextNode = nextNode->next;

      nodeElem = nextNode->next->elem;
      nextNode->next->prev = NULL;
      nextNode->next = NULL;
    }
  return nodeElem;
}
