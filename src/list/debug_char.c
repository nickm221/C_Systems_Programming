#include "mylist.h"

/* Nicholas Massa
 * debug_char prints out the entire list assuming they are all characters
 * Pre: Takes the head of a list of characters
 * Post: Prints the characters
 *
 */

void debug_char(t_node* head)
{
  t_node* nextNode = head;

  if(head == NULL)
    my_str("The list is empty");
  while(nextNode != NULL)
    {
      print_char(nextNode);
      nextNode = nextNode->next;
    }

}
