#include "mylist.h"

/* Nicholas Massa
 * print_int prints a node containing an integer and its next and prev
 * Pre: Takes a node to print
 * Post: Prints the node
 *
 */

void print_int(t_node* head)
{
    if(head->prev == NULL || head->prev->elem == NULL)
    {
        my_str("(N");
    }
    else
    {
        my_str("(");
        my_int((*((int*) (head->prev->elem))));
    }

    my_str("<-");

    if(head->elem == NULL)
    {
        my_str("N");
    }
    else
    {
        my_int((*((int*) (head->elem))));
    }

    my_str("->");

    if(head->next == NULL || head->next->elem == NULL)
    {
        my_str("N");
    }
    else
    {
        my_int((*((int*) (head->next->elem))));
    }

    my_str(") ");
}
