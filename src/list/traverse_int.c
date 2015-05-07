
#include "mylist.h"

/* Nicholas Massa
 * traverse_int prints out the list assuming each element is an integer
 * Pre: Takes in the head of the list
 * Post: The list is printed
 *
 */

void traverse_int(t_node* head)
{
    t_node* nextNode;
    if (head != NULL) {
        nextNode = head;
        while (nextNode->next != NULL) {
            my_int(*(int*)nextNode->elem);
            my_char(' ');
            nextNode= nextNode->next;
        }
        my_int(*(int*)nextNode->elem);
	my_char(' ');
    }
    else
    {
	my_str("The list is empty\n");
	return;
     }
}
