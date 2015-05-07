#include "mylist.h"

/* Nicholas Massa
 * testlist contains tests to run on the Double Linked List
 * 
 *
 *
 */

int main() 
{
    t_node* head = (t_node*) xmalloc(sizeof(t_node));
    t_node* node = (t_node*) xmalloc(sizeof(t_node));
    t_node* testNode = (t_node*) xmalloc(sizeof(t_node));
    t_node* node1 = new_node("Data", NULL, NULL);
    t_node* node2 = new_node("TestIndex1", NULL, NULL);
    t_node* node3 = new_node("MoreData", NULL, NULL);
    char* data = "Node test data";
    char* g = "This";
    char* h = "is";
    char* i = "a";
    char* j = "test";
    char d = 'a';
    char e = 'b';
    char f = 'c';
    int a = 4;
    int b = 8;
    int c = 10;
    int num = 1 << (8 * sizeof(int) - 1);


/* 1. new_node tests */

    my_str("new_node tests: \n \n");
    if((node = new_node(data, NULL, NULL)) != NULL)
      my_str("passed data,nulls\n");
//        debug_string(node);
    else
        my_panic("new_node data, NULL, NULL test FAILED!\n", 1);

    if((node = new_node(NULL, NULL, NULL)) == NULL)
        my_str("new_node NULL, NULL, NULL test passed!\n");
    else
        my_panic("new_node NULL, NULL test FAILED!\n", 1);

    if((node = new_node(NULL, node, head)) == NULL)
        my_str("new_node NULL data test passed!\n");
    else
        my_panic("new_node NULL data test FAILED!\n", 1);
    free(node);
    free(head);
    /*    if((node = new_node(a, node, head)) != NULL)
      my_str("passed");      //debug_int(node);
    else
        my_panic("new_node normal int test FAILED!\n", 1);
    free(node);
    if((node = new_node(d, node, head)) != NULL)
      my_str("passed");      //debug_char(node);
    else
        my_panic("new_node normal char test FAILED!\n", 1);
    free(node);
    */
    if((node = new_node(data, node, head)) != NULL)
      my_str("passed normal \n");      //debug_string(node);
    else
        my_panic("new_node normal string test FAILED!\n", 1);

    my_str("All new_node tests passed \n\n");
    free(head);


/* 2. add_node() tests */

    my_str("add_node tests: \n \n");
    add_node(NULL, &head);
    if(head->next == NULL)
        my_str("add_node NULL node test passed!\n");
    else
        my_panic("add_node NULL node test FAILED!\n", 1);

    add_node(node, NULL);
    if(head->next == NULL) /* Null node is not added */
        my_str("add_node NULL head test passed!\n");
    else
        my_panic("add_node NULL head test FAILED!\n", 1);

    add_node(NULL, NULL);
    if(head->next == NULL)/* Null node is not added */
        my_str("add_node NULL, NULL test passed!\n");
    else
        my_panic("add_node NULL, NULL test FAILED!\n", 1);
    
    testNode = new_node(data, testNode, head);
    add_node(testNode, &head);
    //    debug_string(head);
    if(head->elem == data)
        my_str("add_node normal test passed!\n \n");
    else
        my_panic("add_node normal test FAILED!\n", 1);
    my_str("All add_node tests passed");



/* 3. add_elem() tests */
    my_str("add_elem tests: \n \n");
    add_elem(data, NULL);
    //    debug_string(head);
    if(head->next != NULL)
        my_str("add_elem NULL head test passed!\n");
    else
        my_panic("add_elem NULL head test FAILED!\n", 1);

    add_elem(NULL, NULL);
    // debug_string(head);
    if(head->next != NULL)
        my_str("add_elem NULL, NULL test passed!\n");
    else
        my_panic("add_elem NULL, NULL test FAILED!\n", 1);

    add_elem(data, &head);
    //debug_string(head);
    if(head->next->elem == data)
        my_str("add_elem normal test passed!\n");
    else
        my_panic("add_elem normal test FAILED!\n", 1);

    
    /*   add_elem(num, &head);
    //debug_int(head);
    if(head->next->elem == data)
        my_str("add_elem normal int test passed!\n");
    else
        my_panic("add_elem normal int test FAILED!\n", 1);
    */

    my_str("All add_elem tests passed\n\n");



/*  Empty the list that we just made and set up nodes for next set of tests*/
    empty_list(&head); 
    free(node);
    node = new_node(data, NULL, NULL);

/* 4. append() tests */
    my_str("append tests: \n \n");
    append(NULL, &head);
    //    debug_string(head);
    if(head == NULL)
        my_str("append NULL node test passed!\n");
    else
        my_panic("append NULL node test FAILED!\n", 1);

    append(node, NULL);
    if(head == NULL)
        my_str("append NULL head test passed!\n");
    else
        my_panic("append NULL head test FAILED!\n", 1);

    append(NULL, NULL);
    if(head == NULL)
        my_str("append NULL, NULL test passed!\n");
    else
        my_panic("append NULL, NULL test FAILED!\n", 1);

    add_elem("Test", &head);
    append(node, &head);
    //debug_string(head);
    if(head != NULL && head->next->elem == data)
        my_str("append normal test passed!\n");
    else
        my_panic("append normal test FAILED!\n", 1);

#if 0

/* 10. empty_list() tests */
    my_str("empty_list tests: \n \n");
    empty_list(NULL);
    debug_string(head);
    if(head->next != NULL)
        my_str("empty_list NULL test passed!\n");
    else
        my_panic("empty_list NULL test FAILED!\n", 1);

    empty_list(&head);
    debug_string(head);
    if(head == NULL)
        my_str("empty_list normal test passed!\n");
    else
        my_panic("empty_list normal test FAILED!\n",1);

    empty_list(&head); /* empty the empty list */
    debug_string(head);
    if(head == NULL)
        my_str("empty_list empty list test passed!\n \n");
    else
        my_panic("empty_list empty list test FAILED!\n",1);

/* More setup */
    add_elem("Data", &head);
    add_elem("More data", &head);


/* 6. remove_node() tests */
    my_str("remove_node tests: \n \n");
    if(remove_node(NULL) == NULL)
        my_str("remove_node NULL test passed!\n");
    else
        my_panic("remove_node NULL test FAILED!\n", 1);

    debug_string(head);
    if(remove_node(&head) == "More data")
        my_str("remove_node normal test passed!\n");
    else
        my_panic("remove_node normal test FAILED!\n", 1);
    debug_string(head);

    empty_list(&head);
    if(remove_node(&head) == NULL && head == NULL)
        my_str("remove_node empty list test passed!\n \n");
    else
        my_panic("remove_node empty list test FAILED!\n", 1);
    debug_string(head);

/* 5. add_node_at() tests */
    my_str("add_node_at tests: \n \n");
    empty_list(&head);
    node = new_node("Test", NULL);
    add_node_at(node, &head, 0);
    print_string(head);
    if(head->elem == "Test")
        my_str("add_node_at empty list index 0 test passed!\n");
    else
        my_panic("add_node_at empty list index 0 test FAILED!\n", 1);

    add_node_at(node1, &head, 100);
    debug_string(head);
    if(head->next != NULL && head->next->elem == "Data" && head->next->next == NULL && head->prev == NULL)
        my_str("add_node_at index  test passed!\n");
    else
        my_panic("add_node_at index 100 test FAILED!\n", 1);

    add_node_at(node2, &head, 1);
    debug_string(head);
    if(head->next != NULL && head->next->elem == "TestIndex1")
        my_str("add_node_at 0 < num < length(list) test passed!\n");
    else
        my_panic("add_node_at 0 < num < length(list) test FAILED!\n", 1);
    
    add_node_at(NULL, &head, 0);
    debug_string(head);
    if(head->next->next->next == NULL)
        my_str("add_node_at NULL node test passed!\n");
    else
        my_panic("add_node_at NULL node test FAILED!\n", 1);

    add_node_at(node3, NULL, 0);
    debug_string(head);
    if(head->next->elem == "TestPos1")
        my_str("add_node_at NULL head test passed!\n \n");
    else
        my_panic("add_node_at NULL head test FAILED!\n", 1);


/* 8. remove_node_at() tests */
    my_str("remove_node_at tests: \n \n");
    if(remove_node_at(&head, 0) == "Test")
        my_str("remove_node_at head test passed!\n");
    else
        my_panic("remove_node_at head test FAILED!\n", 1);
    debug_string(head);

    if(remove_node_at(NULL, 100) == NULL)
        my_str("remove_node_at NULL test passed!\n");
    else
        my_panic("remove_node_at NULL test FAILED!\n", 1);
    debug_string(head)

    if(remove_node_at(&head, 1) == "Data")
        my_str("remove_node_at 0 < pos < length(list) test passed!\n");
    else
        my_panic("remove_node_at 0 < pos < length(list) test FAILED!\n", 1);
    debug_string(head);

    if(remove_node_at(&head, 100) == "Data")
        my_str("remove_node_at pos > length(list) test passed!\n \n");
    else
        my_panic("remove_node_at pos > length(list) test FAILED!\n", 1);
    debug_string(head);

/* Last setup */
    add_elem("Hello", &head);
    add_elem("Testing123", &head);
    add_elem("What's a pointer?", &head);

/* 7. remove_last() tests */
    my_str("remove_last tests: \n \n");
    debug_string(head);
    if(remove_last(&head) == "Hello")
        my_str("remove_last normal test passed!\n");
    else
        my_panic("remove_last normal test FAILED!\n", 1);
    debug_string(head);

    if(remove_last(NULL) == NULL)
        my_str("remove_last NULL test passed!\n \n");
    else
        my_panic("remove_last NULL test FAILED!\n", 1);

/* 11. node_at() tests */
    my_str("node_at tests: \n \n");
    if(node_at(NULL, 1) == NULL)
        my_str("node_at NULL test passed!\n");
    else
        my_panic("node_at NULL test FAILED!\n", 1);

    if(node_at(head, 100)->elem == "Testing123")
        my_str("node_at num > length(list) test passed!\n");
    else
        my_panic("node_at num > length(list) test FAILED!\n", 1);

    if(node_at(head, 0)->elem == "What's a pointer?")
        my_str("node_at head test passed!\n");
    else
        my_panic("node_at(head, 0)->elem", 1);

    if(node_at(head, 1)->elem == "Testing123")
        my_str("node_at normal test passed!\n \n");
    else
        my_panic("node_at normal test FAILED!\n", 1);

/* 12. elem_at() tests */
    my_str("elem_at tests: \n \n");
    if(elem_at(NULL, 1) == NULL)
        my_str("elem_at NULL test passed!\n");
    else
        my_panic("elem_at NULL test FAILED!\n");

    if(elem_at(head, 100) == "Testing123")
        my_str("elem_at num > length(list) test passed!\n");
    else
        my_panic("elem_at num > length(list) test FAILED!\n");

    if(elem_at(head, 0) == "What are pointers?")
        my_str("elem_at head test passed!\n");
    else
        my_panic("elem_at head test FAILED!\n");

    if(elem_at(head, 1) == "Testing123")
        my_str("elem_at normal test passed!\n \n");
    else
        my_panic("elem_at normal test FAILED!\n");

/* 9. count_nodes() test */
    my_str("count_nodes tests: \n \n");
    if(count_nodes(head) == 2)
        my_str("count_nodes normal test passed!\n");
    else
        my_panic("count_nodes normal test FAILED!\n", 1);

    if(count_nodes(NULL) == 0)
        my_str("count_nodes NULL test passed!\n");
    else
        my_panic("count_nodes NULL test FAILED!\n", 1);

    empty_list(&head);

    if(count_nodes(head) == 0)
        my_str("count_nodes empty list test passed!\n \n");
    else
        my_panic("count_nodes empty list test FAILED!\n", 1);



/* 13. traverse_int tests */
    my_str("traverse_int tests: \n \n");
    add_elem(&a, &head);
    add_elem(&b, &head);
    add_elem(&c, &head);
    debug_int(head);
    traverse_int(NULL); /* Nothing is printed */
    traverse_int(head); /* 10 8 4 is printed */
    
/* 14. traverse_char tests */
    my_str("traverse_char tests: \n \n");
    traverse_char(head);
    empty_list(&head);
    add_elem(&d, &head);
    add_elem(&e, &head);
    add_elem(&f, &head);
    debug_char(head);
    traverse_char(NULL); //Nothing is printed
    traverse_char(head); //cba is printed

/* 15. traverse_string tests */
    my_str("traverse_string tests: \n \n");
    empty_list(&head);
    add_elem(g, &head);
    add_elem(h, &head);
    add_elem(i, &head);
    add_elem(j, &head);
    debug_string(head);
    traverse_string(NULL); //Nothing is printed
    traverse_string(head); //test a is this printed?

    empty_list(&head);
    free(node);
    free(node1);
    free(node2);
    free(node3);
    free(head);

#endif

    return 0;

}
