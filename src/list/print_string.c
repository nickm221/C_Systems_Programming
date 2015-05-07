#include "mylist.h"

/* Nicholas Massa
 * print_string prints a node, prev, and next assuming that the contents are strings
 * Pre: Takes a node to print
 * Post: Prints the requested node
 *
 */

void print_string(t_node* head)
{

    if(head->prev == NULL || head->prev->elem == NULL)
    {
        my_str("(N");
    }
    else
    {
        my_str("(");
        my_str((char*)(head->prev->elem));
    }

    my_str("<-");

    if(head->elem == NULL)
    {
        my_str("N");
    }
    else
    {
        my_str((char*)(head->elem));
    }

    my_str("->");

    if(head->next == NULL || head->next->elem == NULL)
    {
        my_str("N");
    }
    else
    {
        my_str((char*)(head->next->elem));
    }

    my_str(") ");
}
