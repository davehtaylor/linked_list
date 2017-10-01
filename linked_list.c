#include <stdio.h>
#include <stdlib.h>         // for malloc(), free()
#include "linked_list.h"    // our custom header file


// Create list
List *create_list(void)
{
    List *new_list = malloc(sizeof(List));

    // Make sure we were able to allocate the memory
    if (new_list != NULL) 
    {
        new_list->head = NULL;
        new_list->tail = NULL;
        return new_list;
    }
    else 
    {
        fprintf(stderr, "create_list could not allocate memory");
        return NULL;
    }
}


// Create a node
static Node *create_node(int data) 
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
        fprintf(stderr, "create_node could not allocate memory");
        return NULL;
    }
}


// Add an element to the tail of the list
void append_list(List *list, int data) 
{
    // Make sure the list actually exists. If not, we'll create it
    if (list == NULL)
    {
        list = create_list();
    }

    // Check to see if list is empty. If so, we'll create a new node.
    if (list->head == NULL) 
    {
        list->head = list->tail = create_node(data);
    }
    else 
    {
        list->tail->next = create_node(data);
        list->tail = list->tail->next;
    }
}


// Add an element to the head of the list
void prepend_list(List *list, int data) 
{
    Node *first;

    // Make sure the list actually exists. If not, we'll create it
    if (list == NULL)
    {
        list = create_list();
    }

    // Check to see if list is empty. If so, we'll create a new node.
    if (list->head == NULL) 
    {
        list->head = list->tail = create_node(data);
    }
    else 
    {
        first = create_node(data);
        first->next = list->head;
        list->head = first;
    }
}


// Delete head from list
void delete_head(List *list) 
{
    Node *first;
    
    // Make sure the list isn't empty
    if (list->head == NULL) 
    {
        fprintf(stderr, "delete_head has nothing to do");
    }
    
    // If the head is the only node in the list, just free it
    else if (list->head == list->tail) 
    {
        free(list->head);
        list->head = list->tail = NULL;
    }
    else 
    {
        first = list->head->next;
        free(list->head);
        list->head = first;
    }
}


// Delete last node from list
void delete_tail(List *list) 
{
    Node *cursor;

    // Make sure list isn't empty
    if (list->head == NULL) 
    {
        fprintf(stderr, "delete_tail has nothing to do");
    }

    // See if tail is the only node in the list
    else if (list->head == list->tail)
    {
        free(list->tail); 
        list->head = list->tail = NULL;
    }
    else 
    {
        // Go to the next to last node
         for (cursor = list->head; cursor->next != list->tail; cursor = cursor->next)
            ;

        free(list->tail);
        list->tail = cursor;
        list->tail->next = NULL;
    }
}


// Print the data in each node of the list
void print_list(List *list) 
{
    Node* cursor;

    // Make sure list isn't empty
    if (list->head == NULL) 
    {
        printf("<empty list>\n");
    }
    else if (list->head == list->tail)
    {
        printf("%d", list->head->data);
    }
    else 
    {
        for (cursor = list->head; cursor != NULL; cursor = cursor->next)
            printf("%d ", cursor->data);
    }
}


// Destroy a list
List *destroy_list(List *list) 
{
    Node *cursor, *temp;
    
    // Make sure the list isn't empty already
    if (list == NULL)
    {
        return NULL;
    }
    // Make sure the pointers in the list aren't empty
    else if (list->head == NULL)
    {
        free(list);
        return NULL;
    }
    else 
    {
        cursor = list->head;

        while (cursor != NULL) 
        {
            // Save address of next node after cursor then free the cursor 
            temp = cursor->next;
            free(cursor);
            // Move the cursor to the address of the next node stored in temp
            cursor = temp;
        }

        // Free the whole struct
        free(list);

        return NULL;
    }
}
