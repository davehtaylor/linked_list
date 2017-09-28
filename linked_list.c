#include <stdio.h>
#include <stdlib.h>     // for malloc(), free()


// Create a new node in the list
Node* create_node(int data, Node* next) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    // Make sure we were able to allocate the memory
    if (new_node != NULL) 
    {
        new_node->data = data;
        new_node->next = next;
    }
    else 
    {
        fprintf(stderr, "Could not allocate memory");
        exit(0);
    }

    return new_node;
}


// Add an element to the end of the list
Node* append_node(Node* head, int data) 
{
    // Make sure we're not trying to append after NULL
    if (head == NULL) 
    {
        return NULL;
    }
    else 
    {
        Node* cursor = head;
        
        // Go to the end of the list
        while (cursor->next != NULL) 
            cursor = cursor->next;

        Node* new_node = create_node(data, NULL);
        cursor->next = new_node;
        return head;
    }
}


// Delete head from list
Node* delete_head(Node* head) 
{
    // Make sure the list isn't empty
    if (head == NULL) 
        return NULL;
    
    // Otherwise, remove the head
    Node* first = head;
    head = head->next;
    first->next = NULL;

    // If the head is the only node in the list, set head to NULL
    if (first == head) 
        head = NULL;
    
    // Free the deleted node's memory
    free(first);

    return head;
}


// Delete last node from list
Node* delete_last_node(Node* head) 
{
    // Make sure list isn't empty
    if (head == NULL) 
        return NULL;

    // Otherwise, go to the end of the list
    Node* cursor = head;
    Node* last = NULL;

    while (cursor->next != NULL) {
        last = cursor;
        cursor = cursor->next;
    }

    // Remove the last node
    if (last != NULL) 
        last->next = NULL;

    // If we're deleting the last node in the list, set head to NULL
    if (cursor == head) 
        head = NULL;

    // Free the deleted node's memory
    free(cursor);

    return head;
}


// Delete any node from the list 
Node* delete_any_node(Node* head, Node* node_to_delete) 
{
    // Check to see if the list is empty
    if (node_to_delete == NULL) 
        return NULL;

    // Check to see if the node is the first node
    if (node_to_delete == head) 
        return delete_head(head);

    // Check to see if the node is the last node
    if (node_to_delete->next == NULL) 
        return delete_last_node(head);

    /* If the node to delete is anywhere else in the list, walk the list until
     * we come to the node just before the one we want to delete
     */
    Node* cursor = head;

    while (cursor != NULL) 
    {
        if (cursor->next == node_to_delete) 
            break;

        cursor = cursor->next;
    }

    // Now that the node to delete is the node after the cursor
    if (cursor != NULL) 
    {
        // Set a temp node to the node to delete
        Node* temp = cursor->next;
        // Set the cursor->next pointer to the node after the next one
        cursor->next = temp->next;
        // Delete the temp node
        temp->next = NULL;
        free(temp);
    }

    return head;
}


// Count occurrences of particular element in the list
int count_occurrences(Node* head, int user_data) 
{
    Node* cursor = head;
    int occurrences = 0;

    while (cursor != NULL) 
    {
        if (cursor->data == user_data) 
            ++occurrences;

        cursor = cursor->next;
    }

    return occurrences;
}


// Delete all occurences of a number from the list
Node* delete_all_occurrences(Node* head, int user_data) 
{
    Node* cursor = head;

    while (cursor != NULL) 
    {
        if (cursor->data == user_data) 
            cursor = delete_any_node(head, cursor);

        cursor = cursor->next;
    }

    return head;
}


// Print the data in each node of the list
void print_list(Node* head) 
{
    Node* cursor = head;

    while (cursor != NULL) 
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
}


// Destroy a list
void destroy_list(Node* head) 
{
    // Start the cursor on the head
    Node* cursor = head;
    Node* temp;
    
    while (cursor != NULL) 
    {
        // Save address of next node in cursor then free the current node
        temp = cursor->next;
        free(cursor);
        // Move the cursor to the address of the next node stored in temp
        cursor = temp;
    }
}
