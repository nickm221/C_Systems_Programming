#include "mylist.h"

/* Nicholas Massa
 * empty_list clears the list.
 * Pre: The head of the list to clear.
 * Post: The list is emptied
 *
 */

void empty_list(t_node** head)
{
    t_node* nextNode;
    if (head != NULL) {
        nextNode = (*head)->next;
        free(*head);
        *head = NULL;
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
            free(nextNode->prev);
        }
        free(nextNode);
    }
}
