#include "mylist.h"

/* Nicholas Massa
 * append adds an allocated node to the end of the linked list
 * Pre: Takes in a node to add to the list and the head of the list to add it to
 * Post: Adds the node to the end of the list
 *
 */

void append(t_node* node, t_node** head)
{
  t_node * nextNode;
  t_node* previous;
  
  if(head != NULL && node != NULL && *head != NULL)
    {
        previous = *head;
        nextNode = *head;

        while(nextNode != NULL)
          {
            previous = nextNode;
            nextNode = nextNode->next;
          }
        
        if(previous != NULL)
	   {
            previous->next = node;
	     node->prev = previous;
	   }

        else
	   {
            (*head)->next = node;
	      node->prev = *head;
	   }
    }
}
