#include <stdio.h>
#include <stdlib.h>         // for malloc(), free()
#include "linked_list.h"    // our custom header file


// Create a node
Node *create_node(int data) 
{
    Node *new_node = malloc(sizeof(Node));

    // Make sure we were able to allocate the memory
    if (new_node != NULL) 
    {
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }
    else 
    {
        fprintf(stderr, "Could not allocate memory");
        return NULL;
    }
}


// Add an element to the end of the list
Node *append_node(Node *head, int data) 
{
    Node *cursor;         

    // Check to see if list is empty. If so, we'll create a new node.
    if (head == NULL) 
    {
        return create_node(data);
    }
    else 
    {
        // Go to the end of the list
        for (cursor = head; cursor->next != NULL; cursor = cursor->next)
            ;

        cursor->next = create_node(data);

        return head;
    }
}


// Delete head from list
Node *delete_head(Node *head) 
{
    Node *first = head;
    
    // Make sure the list isn't empty
    if (head == NULL) 
        return NULL;
    
    // If the head is the only node in the list, just free it
    else if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }
    else 
    {
        head = head->next;
        free(first);
        return head;
    }
}


// Delete last node from list
Node *delete_tail(Node *head) 
{
    Node *cursor, *temp;

    // Make sure list isn't empty
    if (head == NULL) 
    {
        return NULL;
    }

    // See if head is the only node in the list
    else if (head->next == NULL)
    {
        free(head); 
        return NULL;
    }
    else 
    {
        // Go to the next to the last element in the list
        for (cursor = head; cursor->next->next != NULL; cursor = cursor->next)
            ;

        free(cursor->next);
        cursor->next = NULL;
        return head;
    }
}


// Print the data in each node of the list
void print_list(Node *head) 
{
    Node* cursor = head;

    while (cursor != NULL) 
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
}


// Destroy a list
Node *destroy_list(Node *head) 
{
    Node *cursor, *temp;
    
    while (cursor != NULL) 
    {
        // Save address of next node in cursor then free the current node
        temp = cursor->next;
        free(cursor);
        // Move the cursor to the address of the next node stored in temp
        cursor = temp;
    }

    return NULL;
}
