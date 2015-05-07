/* Gabarros test main */
#include "mylist.h"

int main()
{
  int arr[10] = {4, 65, 32, 1, 68, 23, 83, 12, 6, 82};
  char *str = "Hello!";
  char *str2 = "World!";
  t_node *head = NULL;
  unsigned int i;
  t_node *tmp = NULL;
  int n = 5;
  t_node **test = NULL;
  void *ret = NULL;

  for (i = 0; i < 3; i++)
    add_node(new_node(&arr[i], NULL, NULL), &head);
  traverse_int(head);
  debug_int(head);
  my_char('\n');
  for (; i < 7; i++)
    add_elem(&arr[i], &head);
  debug_int(head);
  my_char('\n');
  for (; i < 10; i++)
    append(new_node(&arr[i], NULL, NULL), &head);
  debug_int(head);
  my_char('\n');
  tmp = new_node(&n, NULL, NULL);
  add_node_at(tmp, &head, 5);
  debug_int(head);
  my_char('\n');
  add_node_at(new_node(&n, NULL, NULL), &head, 0);
  my_str("add node at head: ");
  debug_int(head);
  my_char('\n');
  add_node_at(new_node(&n, NULL, NULL), &head, 564);
  my_str("add node at index 564: ");
  debug_int(head);
  my_char('\n');
  my_str("Count nodes(13): ");
  my_int(count_nodes(head));
  my_char('\n');
  ret = remove_node(&head);
  my_str("Removed Node [at head] (5): ");
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_last(&head);
  my_str("Removed Last(5): ");
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 0);
  my_str("Remove node at [index 0] (83): ");
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 243);
  my_str("Remove node at [index 243] (82): ");
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  ret = remove_node_at(&head, 3);
  my_str("Remove node at[index 3] (32): ");
  my_int(*((int*)ret));
  my_char('\n');
  debug_int(head);
  my_char('\n');
  empty_list(&head);
  my_str("Empties the list: ");
  debug_int(head);
  my_char('\n');
  my_str("add elem Hello");
  add_elem(str2, &head);
  my_char('\n');
  my_str("add elem World");
  add_elem(str, &head);
  my_char('\n');
  debug_string(head);
  my_char('\n');
  traverse_string(head);
  my_char('\n');
  debug_char(head);
  my_char('\n');
  traverse_char(head);
  my_char('\n');
  my_str((char*)elem_at(head, 0)); /* Hello */
  my_char('\n');
  my_str((char*)elem_at(head, 43)); /* World */
  my_char('\n');
  tmp = node_at(head, 0);
  print_string(tmp);
  my_char('\n');
  tmp = node_at(head, 43);
  print_string(tmp);
  my_char('\n');
  empty_list(&head);
  debug_string(head);
  /* this last one is mainly to clear memory */
  return 0;
}

