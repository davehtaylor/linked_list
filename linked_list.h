#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// The public interface to our linked list
typedef struct List List;

// Create a list
List *create_list(void);

// Append an element
void append_list(List *list, int data); 

// Prepend an element
void prepend_list(List *list, int data);

// Delete head from list
void delete_head(List *list); 

// Delete last node from list
void delete_tail(List *list); 

// Delete arbitrary element from list
void delete_index(List *list, int index);

// Delete all occurrences of a particular from list
void delete_all_value(List *list, int key);

// Count the number of elements in list
int list_length(List *list);

// Concatenate two lists
List *list_cat(List *dest, List *list1, List *list2);

// Count occurrences of a particular value
int count_value(List *list, int key);

// Print specific element, indexed from 0 
void print_index(List *list, int index);

// Print the entire list
void print_list(List *list); 

// Print the entire list in reverse order
void print_list_reverse(List *list); 

// Destroy a list
List *destroy_list(List *list); 

#endif  // LINKED_LIST_H
