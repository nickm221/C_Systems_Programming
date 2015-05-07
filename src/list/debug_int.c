#include "mylist.h"

/* Nicholas Massa
 * debug_int.c prints out the entire list in the format(prev<-curr->next)
 * Pre: Takes in a node containing integer elements
 * Post: Prints the entire list
 *
 */

void debug_int(t_node* head)
{
  if(head == NULL)
    my_str("The list is empty\n");
  while(head != NULL)
    {
      print_int(head);
      head = head->next;
    }
  
}
