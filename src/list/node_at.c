#include "mylist.h"

/* Nicholas Massa
 * node_at returns the node at the specified index
 * Pre: A valid head and an unsigned int index
 * Post: returns a pointer to the node
 *
 */

t_node* node_at(t_node* head, unsigned int num)
{
    t_node* nextNode = NULL;

    if(head != NULL)
    {
        nextNode = head;

        while(nextNode->next != NULL && num > 0)
        {
            nextNode = nextNode->next;
            num--;
        }
    }

    return nextNode;
}