#include "mylist.h"

/* Nicholas Massa
 * elem_at returns the element at the index requested
 * Pre: Takes the head of the list and the index of an element to return
 * Post: Returns the element in the given node
 *
 */

void* elem_at(t_node* head, unsigned int num)
{
    void* nodeElem = NULL;
    t_node* counter;

    if(head != NULL)
    {
        counter = head;

        for( ; num > 0 && counter->next != NULL; counter = counter->next, num--)
            ;

        nodeElem = counter->elem;
    }

    return nodeElem;
}