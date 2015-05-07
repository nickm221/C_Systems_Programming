#include "mylist.h"

/* Nicholas Massa
 * traverse_string prints out the list assuming its made up of strings
 * Pre: Takes in the head of a list
 * Post: Prints the list
 *
 */

void traverse_string(t_node* head)
{
    t_node* nextNode = head;

    if(head == NULL)
      {
	my_str("The list is empty\n");
	return;
      }

    while(nextNode != NULL)
    {
        if(nextNode->elem == NULL)
            my_str("NULL");
        else
            my_str(nextNode->elem);

        my_str(" ");
        nextNode = nextNode->next;
    }
}
