/* Nicholas Massa
 * Header for the Linked List 
 * Contains struct for nodes and all functions
 * to be included in the implementation
 *
 */

#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "my.h"

typedef struct s_node
{
  void * elem;
  struct s_node *next;
  struct s_node *prev;
}        t_node;

/* Test Functions */

void debug_string(t_node*); // Prints strings in the form of (Prev<-Curr->Next)  

void debug_int(t_node*); // Prints ints in the form of (Prev<-Curr->Next)  

void debug_char(t_node*); // Prints chars in the form of (Prev<-Curr->Next)  

void print_string(t_node*); // Prints a single string in the form of (Prev<-Curr->Next)  

void print_int(t_node*); // Prints a single int in the form of (Prev<-Curr->Next)  

void print_char(t_node*); // Prints a single char in the form of (Prev<-Curr->Next)  

/* Linked list functions */

t_node *new_node(void *, t_node *, t_node *); // Allocatenew node with elem next and prev

void add_node(t_node*, t_node**); // Add a node at te head of the list

void add_elem(void*, t_node**); // Create a node with an element then add to the list

void append(t_node*, t_node**); // Places a new node at the end of the list 

void add_node_at(t_node*, t_node**, unsigned int); // Adds node at specified index

void *remove_node(t_node**); // Removes the entire first node

void *remove_node_at(t_node**, unsigned int); // Removes the node at the specified index

void *remove_last(t_node**); // Removes the last node in the linked list

unsigned int count_nodes(t_node*); // counts the number of nodes in the list

void empty_list(t_node**); // empties the list (2 lines of code)

t_node *node_at(t_node*, unsigned int); // Returns the node at the specified index

void *elem_at(t_node*, unsigned int); // Returns the element at the specified index

void traverse_int(t_node*); // Prints the list of ints.If empty print "The list is empty\n" 

void traverse_string(t_node*); // Prints the list of ints. Empty:  "The list is empty\n" 

void traverse_char(t_node*); // Prints the list of ints.If empty: "The list is empty\n" 

#endif
