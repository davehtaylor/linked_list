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

 
// Delete element helper function
static void delete_next_element(List* list, Node *node)
{
    Node *temp;

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
        temp = node->next->next;
        temp->prev = node;

        free(node->next);
        node->next = temp;
    }
}


// Min of two helper function
static int min(int i, int j)
{
    return (i < j) ? i : j;
}


// Max of two helper function
static int max(int i, int j)
{
    return (i > j) ? i : j;
}


// Create node helper function 
static Node *create_node(int data) 
{
    Node *new_node = NULL;
    
    new_node = malloc(sizeof(Node));

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
    List *new_list = NULL;
    
    new_list = malloc(sizeof(List));

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
        // Go to the tail and create a new node afterward, then link
        // the all up
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


// Insert at arbitrary point
void list_insert(List *list, int index, int data)
{   
    int i;
    Node *cursor, *temp;

    // Make sure list exists, that it's not empty, or if we're trying to
    // otherwise insert at the head
    if (list == NULL || list->head == NULL || index == 0 || 
        list->head == list->tail)
    {
        prepend_list(list, data);
    }
    // See if we're trying to insert out of bounds
    else if (index < 0 || index >= list->length)
    {
        fprintf(stderr, "insert_list cannot insert beyond list bounds");
    }
    // See if we're inserting at the tail
    else if (index == (list->length - 1))
    {
        append_list(list, data);
    }
    else
    {
        cursor = list->head;

        // Go to the element before the index we're inserting at
        for (i = 0; i < (index - 1); i++)
           cursor = cursor->next; 

        // Save the next element, create the new node after cursor, and link
        // them all back up
        temp = cursor->next;
        cursor->next = create_node(data);
        temp->prev = cursor->next;
        cursor->next->next = temp;
        cursor->next->prev = cursor;
        list->length++;
    }

}


// Swap two elements
void list_swap(List* list, int index1, int index2)
{
    // Figure out which comes first in the list, to simplify which way to walk
    // the list when finding the next index. This way, it doesn't matter which
    // index the user passes to the function first
    int i, temp, lo = min(index1, index2), hi = max(index1, index2);
    Node *cursor1, *cursor2;

    // Go to first element
    for (i = 0, cursor1 = list->head; i < lo; i++)
        cursor1 = cursor1->next;

    // Go to second element, starting from the first element. No need to walk
    // whole list again
    for (i = lo, cursor2 = cursor1; i < hi; i++)
        cursor2 = cursor2->next;

    // Just swap the data 
    temp = cursor1->data;
    cursor1->data = cursor2->data;
    cursor2->data = temp;
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


// Concatenate two lists. The second list will be added on to the first. 
List *list_cat(List **list1, List **list2)
{
    // I'm sure some of these conditions could be combined, but I'm breaking
    // them out for readability. 
    //
    // Since we're concatenating the lists, list1 will hold both lists. So
    // while the addresses of the nodes in list2 will still be valid, the
    // outer struct will no longer be needed. We we'll free the struct 
    // when necessary. And when we destroy list1, all the former list2 nodes
    // should be properly freed. Hopefully this will avoid memory leaks. 

    // If both lists are NULL
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    // If only list2 is NULL
    else if (list1 != NULL && list2 == NULL)
    {
        return *list1;
    }
    // If only list1 is NULL
    else if (list1 == NULL && list2 != NULL)
    {
        list1 = list2;

        free(*list2);
        *list2 = NULL;

        return *list1;
    }
    // If list1 is not NULL, but is empty
    else if ((list1 != NULL && (*list1)->head == NULL) && 
            (list2 != NULL && (*list2)->head != NULL))
    {
        (*list1)->head = (*list2)->head;
        (*list1)->tail = (*list2)->tail;

        free(*list2);
        *list2 = NULL;

        return *list1;
    }
    // If list2 is not NULL, but is empty
    else if ((list1 != NULL && (*list1)->head != NULL) && 
            (list2 != NULL && (*list2)->head == NULL))
    {
        free(*list2);
        *list2 = NULL;

        return *list1;
    }
    else 
    {
        (*list1)->tail->next = (*list2)->head;
        (*list1)->tail = (*list2)->tail;

        free(*list2);
        *list2 = NULL;

        return *list1;
    }
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


// Sort the list in non-decreasing order (Bubble Sort)
void list_sort(List *list)
{
    int temp, did_swap = 1;
    Node *cursor;

    while (did_swap)
    {
        did_swap = 0;

        for (cursor = list->head; cursor != list->tail; cursor = cursor->next)
        {
            if (cursor->data > cursor->next->data)
            {
                temp = cursor->data;
                cursor->data = cursor->next->data;
                cursor->next->data = temp;

                did_swap = 1;
            }
        }
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
    else if (list != NULL && list->head == NULL)
    {
        printf("<empty list>\n");
    }
    // See if the user is asking for an invalid index
    else if (index < 0 || index >= list->length)
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
        for (i = 0, cursor = list->head; i < index; i++)
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
    else if (list != NULL && list->head == NULL)
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
    else if (list != NULL && list->head == NULL)
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
            printf("%d%c", cursor->data, (cursor->prev == NULL) ? '\n' : ' ');
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
        cursor = list->tail->prev;
        
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
    Node *cursor;

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
        for (i = 0; i < (index - 1); i++)
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
        // First check if the head contains the value and delete it if so. 
        // Keep deleting if the value is repeated afterward. If we end up
        // deleting the whole list (e.g a list of the same value), just return
        if (list->head->data == key)
            while (list->head->data == key)
            {
                delete_head(list);
                if (list->head == NULL)
                    return;
            }
        
        for (cursor = list->head; cursor != list->tail; cursor = cursor->next)
        {
            // We need a while loop here in case the same value is
            // repeated, just like we did with the case of deleting head 
            if (cursor->next->data == key)
            {
                while (cursor->next->data == key)
                {
                    delete_next_element(list, cursor);
                    list->length--;
                }
            }
        }
    }
}


// Destroy a list
static void destroy_list_helper(Node *head) 
{
    if (head == NULL)
        return;

    destroy_list_helper(head->next);
    free(head);
}


// Gateway function for list destruction
List *destroy_list(List *list)
{
    // Make sure the list exists
    if (list == NULL)
    {
        return NULL;
    }
    // See if the list is empty
    else if (list != NULL && list->head == NULL)
    {
        free(list);
        return NULL;
    }
    // Free all the nodes recursively, then free the list struct
    else
    {
        destroy_list_helper(list->head);
        free(list);
        return NULL;
    }
}
