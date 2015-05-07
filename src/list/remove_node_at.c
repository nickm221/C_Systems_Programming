#include "mylist.h"

/* Nicholas Massa
 * remove_node_at removes a node at the specified index, returning the element within
 * Pre: Takes in the head of a list and the index of the element to be removed
 * Post: Removes the node and returns the element within the node
 *
 */

void* remove_node_at(t_node** head, unsigned int pos)
{
    t_node* previous;
    t_node* nextNode;
    void* returnElem = NULL;
    int i = 0;
    if(head != NULL)
    {
        if(pos == 0)
            returnElem = remove_node(head);
        else
        {
            nextNode = (*head)->next;

            while(i < pos && nextNode != NULL)
            {
                previous = nextNode;
                nextNode = nextNode->next;
                i++;
            }
        if (previous->prev != NULL)
            previous->prev->next = nextNode;
        else
            *head = previous->next;
        if (nextNode != NULL)
            nextNode->prev = previous->prev;
        previous->prev = NULL;
        previous->next = NULL;
        returnElem = previous->elem;
        }
    }

    return returnElem;
}
