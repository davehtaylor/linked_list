#include <stdio.h>
#include <stdlib.h>         // for malloc(), free()
#include "linked_list.h"    // our linked list header file


// Structure for our doubly-linked list, with one element of int data
typedef struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;


// Structure to hold head and tail pointers, as well as length of list. 
// This will be the public interface to the linked list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

 
// Destroy nodes helper function
static void destroy_nodes(Node *head)
{
    Node *cursor = head, *temp;

    while (cursor != NULL) 
    {
        // Save address of next node after cursor then free the cursor 
        temp = cursor->next;
        free(cursor);
        // Move the cursor to the address of the next node stored in temp
        cursor = temp;
    }
}


// Delete element helper function
static void delete_next_element(List* list, Node *node)
{
    Node *temp1, *temp2;

    // Make sure we're not trying to delete past the end
    if (node->next == NULL)
    {
        fprintf(stderr, "delete_element has nothing to do\n");
    }
    // See if the current element will become the new tail 
    else if (node->next == list->tail)
    {
        free(node->next);
        node->next = NULL;
        list->tail = node;
    }
    else
    {
        // Need to make sure we grab the prev as well as the next
        temp1 = node->next->next;
        temp2 = node->next->next->prev;

        free(node->next);
        node->next = temp1;
        node->next->prev = node;
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
        new_node->prev = NULL;
        new_node->next = NULL;
        return new_node;
    }
    else 
    {
        fprintf(stderr, "create_node could not allocate memory\n");
        return NULL;
    }
}


// Create list
List *create_list(void)
{
    List *new_list = malloc(sizeof(List));

    // Make sure we were able to allocate the memory
    if (new_list != NULL) 
    {
        new_list->head = NULL;
        new_list->tail = NULL;
        new_list->length = 0;
        return new_list;
    }
    else 
    {
        fprintf(stderr, "create_list could not allocate memory\n");
        return NULL;
    }
}


// Add an element to the tail of the list
void append_list(List *list, int data) 
{
    Node *temp;

    // Make sure the list actually exists. If not, we'll create it
    if (list == NULL)
    {
        list = create_list();
    }
    
    // Check to see if list is empty. If so, we'll create a new node.
    if (list->head == NULL) 
    {
        list->head = list->tail = create_node(data);
        list->length = 1;
    }
    else 
    {
        list->tail->next = create_node(data);
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
        list->length++;
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
    else if (list->head == NULL) 
    {
        list->head = list->tail = create_node(data);
        list->length = 1;
    }
    else 
    {
        // Make a new node, set its next equal to head, make the new node the
        // head, the set the old head's prev equal to the new head
        first = create_node(data);
        first->next = list->head;
        list->head = first;
        list->head->next->prev = list->head;
        list->length++;
    }
}


// Count the number of elements in the list
int list_length(List *list)
{
    // Make sure list exists, or if it's empty 
    if (list == NULL || list->head == NULL)
       return 0; 
    else
        return list->length;
}


// Concatenate two lists
List *list_cat(List* dest, List *list1, List *list2)
{
    // See if the destination exists
    if (dest == NULL)
    {
        dest = create_list();
    }

    // See if there is something in the destination list. If so,
    // we'll destroy it so we don't leak memory
    if (dest->head != NULL)
    {
        destroy_nodes(dest->head); 
    }
    
    // Get the info from the first list
    dest->head = list1->head;
    dest->tail = list1->tail;

    // Now connecting them
    dest->tail->next = list2->head;
    dest->tail = list2->tail;

    return dest;
}


// Reverse list
void reverse_list(List *list)
{
    Node *temp, *cursor;

    // Move along the list swapping the prev and next pointers
    for (cursor = list->tail; cursor != NULL; cursor = cursor->next)
    {
        temp = cursor->next;
        cursor->next = cursor->prev;
        cursor->prev = temp;
    }

    // Now swap the head and tail pointers
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;

    printf("Head: %d, tail: %d\n", list->head->data, list->tail->data);
}


// Count occurrences of a particular value
int count_value(List *list, int key)
{
    int count = 0;
    Node *cursor;

    // Make sure list exists, or if it's empty 
    if (list == NULL || list->head == NULL) 
    {
        return 0;
    }
    else
    {
        // Walk the list and increment the counter if we find our key
        for (cursor = list->head; cursor != NULL; cursor = cursor->next)
            if (cursor->data == key)
                count++; 

        return count;
    }
}


// Print specific element, indexed from 0
void print_index(List *list, int index)
{
    Node* cursor;
    int i;

    // Make sure list is initialized
    if (list == NULL) 
    {
        printf("<list does not exist>\n"); 
    }
    // Make sure the list isn't empty
    else if (list->head == NULL)
    {
        printf("<empty list>\n");
    }
    // See if the user is asking for an invalid index
    else if (index < 0 || index > list->length)
    {
        printf("<index out of bounds>\n");
    }
    // See if there is only one element in the list
    else if (index == 0 || list->head == list->tail)
    {
        printf("%d\n", list->head->data);
    }
    else 
    {
        // Go to the index, then print it
        for (i = 0, cursor = list->head; i < (index - 1); i++)
            cursor = cursor->next;

        printf("%d\n", cursor->data);
    }
}


// Print the data in each node of the list
void print_list(List *list) 
{
    Node* cursor;

    // Make sure list is initialized
    if (list == NULL) 
    {
        printf("<list does not exist>\n"); 
    }
    // Make sure the list isn't empty
    else if (list->head == NULL)
    {
        printf("<empty list>\n");
    }
    // See if there is only one element in the list
    else if (list->head == list->tail)
    {
        printf("%d\n", list->head->data);
    }
    else 
    {
        for (cursor = list->head; cursor != NULL; cursor = cursor->next)
            // Print trailing space if more elements, new line if not
            printf("%d%c", cursor->data, (cursor->next == NULL) ? '\n' : ' ');
    }
}


// Print the data in each node of the list in reverse order
void print_list_reverse(List *list) 
{
    Node* cursor;

    // Make sure list is initialized
    if (list == NULL) 
    {
        printf("<list does not exist>\n"); 
    }
    // Make sure the list isn't empty
    else if (list->head == NULL)
    {
        printf("<empty list>\n");
    }
    // See if there is only one element in the list
    else if (list->head == list->tail)
    {
        printf("%d\n", list->head->data);
    }
    else 
    {
        for (cursor = list->tail; cursor != NULL; cursor = cursor->prev)
            // Print trailing space if more elements, new line if not
            printf("%d%c", cursor->data, (cursor->next == NULL) ? '\n' : ' ');
    }
}


// Delete head from list
void delete_head(List *list) 
{
    Node *first;
    
    // Make sure list exists, and that it's not empty
    if (list == NULL || list->head == NULL)
    {
        fprintf(stderr, "delete_head has nothing to do\n");
    }
    // If the head is the only node in the list, just free it
    else if (list->head == list->tail) 
    {
        free(list->head);
        list->head = list->tail = NULL;
        list->length = 0;
    }
    else 
    {
        // Save the second element in the list, free the head, set the
        // second element to the new head, and set its prev to NULL
        first = list->head->next;
        free(list->head);
        list->head = first;
        list->head->prev = NULL;
        list->length--;
    }
}


// Delete last node from list
void delete_tail(List *list) 
{
    Node *cursor;

    // Make sure list exists, and that it's not empty
    if (list == NULL || list->head == NULL)
    {
        fprintf(stderr, "delete_tail has nothing to do\n");
    }
    // See if tail is the only node in the list
    else if (list->head == list->tail)
    {
        free(list->tail); 
        list->head = list->tail = NULL;
        list->length = 0;
    }
    else 
    {
        // Go to the next to last node
        for (cursor = list->head; cursor->next != list->tail; cursor = cursor->next)
            ;
        
        // Free the tail, set the tail to the current node, set next to NULL
        free(list->tail);
        list->tail = cursor;
        list->tail->next = NULL;
        list->length--;
    }
}


// Delete arbitrary element from list
void delete_index(List *list, int index)
{
    int i;
    Node *cursor, *temp;

    // Make sure list exists, and that it's not empty
    if (list == NULL || list->head == NULL)
    {
        fprintf(stderr, "delete_element has nothing to do\n");
    }
    // See if we're deleting the head, or if there is only one element in list
    else if (index == 0 || list->head == list->tail)
    {
        delete_head(list);
    }
    else
    {
        cursor = list->head;

        // Go to the element before the one we're going to delete
        for (i = 1; i < (index - 1); i++)
           cursor = cursor->next; 

        delete_next_element(list, cursor);
        list->length--;
    }
}


// Delete occurrences of a particular value
void delete_all_value(List *list, int key)
{
    Node *cursor;

    // Make sure list is initialized, and that it's not empty
    if (list == NULL || list->head == NULL) 
    {
        fprintf(stderr, "delete_all_value has nothing to do\n");
    }
    else
    {
        // First check if the head contains the value, keep going if necessary
        if (list->head->data == key)
            while (list->head->data == key)
                delete_head(list);
        
        cursor = list->head;

        // We want this code to run at least once before looping
        do 
        {
            if (cursor->next->data == key)
                delete_next_element(list, cursor);

            cursor = cursor->next;
            list->length--;
        }
        while (cursor != list->tail);
    }
}


// Destroy a list
List *destroy_list(List *list) 
{
    // Make sure the list exists
    if (list == NULL)
    {
        return NULL;
    }
    // See if the list is empty
    else if (list->head == NULL)
    {
        free(list);
        return NULL;
    }
    else 
    {
        destroy_nodes(list->head);

        // Free the whole struct
        free(list);

        return NULL;
    }
}
