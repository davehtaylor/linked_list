#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Structure for our linked list
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Create a new node
Node *create_node(int data); 

// Add an element to the end of the list
Node *append_node(Node *head, int data); 

// Delete head from list
Node *delete_head(Node *head); 

// Delete last node from list
Node *delete_tail(Node *head); 

// Print the data in each node of the list
void print_list(Node *head); 

// Destroy a list
Node *destroy_list(Node *head); 

#endif
