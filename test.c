#include <stdio.h>
#include "linked_list.h"

int main(void)
{

    List *list = NULL;

    // Create list
    printf("-> Creating list\n");
    list = create_list();
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
