/* Test cases for linked list module */

#include <stdio.h>
#include "linked_list.h"

int main(void)
{

    List *list = NULL;
    int len;

    // Test non-existent list
    printf("-> Testing null list\n");
    print_list(list);
    putchar('\n');

    // Create list
    printf("-> Creating list\n");
    list = create_list();
    print_list(list);
    putchar('\n');

    // Append
    printf("-> Appending\n");
    append_list(list, 95);
    print_list(list);
    putchar('\n');

    // Append
    printf("-> Appending\n");
    append_list(list, 2501);
    print_list(list);
    putchar('\n');

    // Prepend
    printf("-> Prepending\n");
    prepend_list(list, 2095);
    print_list(list);
    putchar('\n');

    // Prepend
    printf("-> Prepending\n");
    prepend_list(list, 8575);
    print_list(list);
    putchar('\n');

    // Count list
    printf("-> About to count the elements in list\n");
    len = count_list(list);
    printf("List is %d nodes long\n", len);
    
    // Delete head
    printf("-> About to delete head\n");
    delete_head(list);
    print_list(list);
    putchar('\n');

    // Delete tail
    printf("-> About to delete tail\n");
    delete_tail(list);
    print_list(list);
    putchar('\n');

    // Destroy it
    printf("-> About to destroy list\n");
    list = destroy_list(list);
    if (list == NULL)
        printf("-> List destroyed\n");

    return 0;
}
