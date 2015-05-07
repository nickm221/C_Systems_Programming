#include "mylist.h"

/* Nicholas Massa
 * print_char prints a node containing an char and its next and prev
 * Pre: Takes a node to print
 * Post: Prints the node
 *
 */

void print_char(t_node* head)
{

    if(head->prev == NULL || head->prev->elem == NULL)
    {
        my_str("(N");
    }
    else
    {
        my_str("(");
        my_char(*((char*)(head->prev->elem)));
    }

    my_str("<-");

    if(head->elem == NULL)
    {
        my_str("N");
    }
    else
    {
         my_char(*((char*)(head->elem)));
    }

    my_str("->");

    if(head->next == NULL || head->next->elem == NULL)
    {
        my_str("N");
    }
    else
    {
         my_char(*((char*)(head->next->elem)));
    }

    my_str(") ");
}
