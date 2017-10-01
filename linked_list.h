#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Structure for our linked list, with one element of int data
typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

/* Structure to hold head and tail pointers. This will be the public interface
 * to the linked list
 */
typedef struct List
{
    Node *head;
    Node *tail;
} List;

// Create a list
List *create_list(void);

// Append an element
void append_list(List *list, int data); 

// Prepend and element
void prepend_list(List *list, int data);

// Count list
int count_list(List *list);

// Delete head from list
void delete_head(List *list); 

// Delete last node from list
void delete_tail(List *list); 

// Count elements in list
int count_list(List *list);

// Print the data in each node of the list
void print_list(List *list); 

// Destroy a list
List *destroy_list(List *list); 

#endif
