#include "mylist.h"

/* Nicholas Massa
 * remove_node removes the first node in the list and returns a ptr to the element within
 * Pre: Takes the head of atleast one node length
 * Post: Removes the first node and returns a pointer to the data
 *
 */

void *remove_node(t_node** head)
{
  void* nodeElem = NULL;
  t_node* nextOfHead;

  if(head != NULL && *head != NULL)
    {
      nextOfHead = *head;
      nodeElem = (*head)->elem;
      *head = nextOfHead->next;
      free(nextOfHead);
      nextOfHead = NULL;
      (*head)->prev = NULL; //MAYBE?
    }
  return nodeElem;


}
