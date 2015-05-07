#include "mylist.h"

/* Nicholas Massa
 * add_node_at adds a node at the specified index
 * Pre: Takes the node to add, the head of the list, and the index of the new node
 * Post: Adds the node to the list at the specified index
 *
 */

void add_node_at(t_node* node, t_node** head, unsigned int n) {
    t_node* nextNode;
    int i = 0;
    if (head != NULL) {
        nextNode = *head;
        while (nextNode->next != NULL && i < n) { //get to specified index
            nextNode = nextNode->next;
            i++;
        }
        if (nextNode->next != NULL) {
            if(node != NULL) 
	      node->next = nextNode; //if node is not null set its next to the node after it
            if(nextNode->prev != NULL) 
	      nextNode->prev->next = node; // set the next of the node before node
            else 
	      *head = node; //set the head of the list to be the node if it's null
            if(node!= NULL)
	      node->prev = nextNode->prev;
            nextNode->prev = node;
        }
        else{
            nextNode->next = node;
            if(node != NULL)node->prev = nextNode;
        }
    }
}
