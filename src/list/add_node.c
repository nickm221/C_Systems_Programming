#include "mylist.h"

/* Nicholas Massa
 * add_node adds a node to the front of the list
 * Pre: Node is already allocated. Head cannot be null
 * Post: Node is added to the front of the list
 *
 */

void add_node(t_node* node, t_node** head)
{
    if(node != NULL && head != NULL)
    {
        if(*head == NULL)
            *head = node;
        else
        {
            node->next = *head;
	    node->prev = NULL;
            (*head)->prev = node;
	    *head = node;
	    
        }
    }
}
