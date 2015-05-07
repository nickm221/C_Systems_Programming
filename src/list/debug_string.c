#include "mylist.h"

/* Nicholas Massa
 * debug_string prints an entire list assuming the elements are strings
 * Pre: Takes the head of a list
 * Post: Prints the list 
 *
 */

void debug_string(t_node* head)
{
  t_node* nextNode = head;

  if(head == NULL)
    my_str("The list is empty\n");
  while(nextNode != NULL)
    {
      print_string(nextNode);
      nextNode = nextNode->next;
    }

}
