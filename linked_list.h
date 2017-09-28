#ifndef
#define LINKED_LIST_H

// Structure for our linked list
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Create a new node in the list
Node* create_node(int data, Node* next); 

// Add an element to the end of the list
Node* append_node(Node* head, int data); 

// Delete head from list
Node* delete_head(Node* head); 

// Delete last node from list
Node* delete_last_node(Node* head); 

// Delete any node from the list 
Node* delete_any_node(Node* head, Node* node_to_delete); 

// Count occurrences of particular element in the list
int count_occurrences(Node* head, int user_data);

// Delete all occurences of a number from the list
Node* delete_all_occurrences(Node* head, int user_data); 

// Print the data in each node of the list
void print_list(Node* head); 

// Destroy a list
void destroy_list(Node* head); 

#endif
