#include "mylist.h"

/* Nicholas Massa
 * count_nodes counts the number of nodes in the current list
 * Pre: The head of the list that the function should count
 * Post: The number of nodes
 *
 */

unsigned int count_nodes(t_node* head)
{
    unsigned int num = 0;

    if(head != NULL)
    {
        t_node* nextElem = head;

        while(nextElem != NULL)
        {
            nextElem = nextElem->next;
            num++;
        }
    }

    return num;
}