#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    Node *head = NULL;

    // Create list
    printf("-> Creating list\n");
    head = create_node(95);
    print_list(head);
    putchar('\n');

    // Append
    printf("-> Appending\n");
    head = append_node(head, 8575);
    print_list(head);
    putchar('\n');

    // Append
    printf("-> Appending\n");
    head = append_node(head, 2501);
    print_list(head);
    putchar('\n');

    // Delete head
    printf("-> About to delete head\n");
    head = delete_head(head);
    print_list(head);
    putchar('\n');

    // Delete tail
    printf("-> About to delete tail\n");
    head = delete_tail(head);
    print_list(head);
    putchar('\n');

    // Destroy it
    printf("-> About to destroy list\n");
    head = destroy_list(head);
    if (head == NULL)
        printf("-> List destroyed\n");

    return 0;
}
