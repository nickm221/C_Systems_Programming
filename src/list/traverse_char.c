#include "mylist.h"

/* Nicholas Massa
 * traverse_char prints the list assuming all letters are chars
 * Pre: Takes in the head of a list
 * Post: The list of chars is printed
 *
 */

void traverse_char(t_node* head)
{
    t_node* nextNode = head;
    char* ptr;

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
        {
            ptr = (char*) nextNode->elem;
            my_char(*ptr);
        }

        my_str(" ");
        nextNode = nextNode->next;
    }
}
