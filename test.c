/* Test cases for linked list module */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(void)
{

    List *list = NULL;
    int i, len, count;
    srand(time(NULL));

    // Test non-existent list
    printf("-> Testing null list\n");
    print_list(list);

    // Create list
    printf("-> Creating list\n");
    list = create_list();
    print_list(list);

    // Append
    printf("-> Appending\n");
    append_list(list, 95);
    print_list(list);

    // Append
    printf("-> Appending\n");
    append_list(list, 2501);
    print_list(list);

    // Prepend
    printf("-> Prepending\n");
    prepend_list(list, 2095);
    print_list(list);

    // Prepend
    printf("-> Prepending\n");
    prepend_list(list, 95);
    print_list(list);

    // Prepend
    printf("-> Prepending\n");
    prepend_list(list, 95);
    print_list(list);

    // Append a bunch
    printf("-> Appending a bunch of random values\n");
    for (i = 0; i < 45; i++)
    {
        append_list(list, (rand() % 20 + 1));
    }
    print_list(list);

    // Append
    printf("-> Appending\n");
    append_list(list, 95);
    print_list(list);

    // Append
    printf("-> Appending\n");
    append_list(list, 107);
    print_list(list);

    // List length
    printf("-> About to count the elements in list\n");
    len = list_length(list);
    printf("List is %d nodes long\n", len);
    
    // Count occurrences of a particular element
    printf("-> About to count occurrences of '95' in list\n");
    count = count_value(list, 95);
    printf("'95' appears %d times\n", count);

    // Delete occurences of a particular element
    printf("-> About to delete all occurences of '95' in list\n");
    delete_all_value(list, 95);
    print_list(list);

    // Delete arbitrary element
    printf("-> About to delete an arbitrary element\n");
    delete_index(list, 1);
    print_list(list);

    // Delete head
    printf("-> About to delete head\n");
    delete_head(list);
    print_list(list);

    // Delete tail
    printf("-> About to delete tail\n");
    delete_tail(list);
    print_list(list);
    
    // Destroy it
    printf("-> About to destroy list\n");
    list = destroy_list(list);
    if (list == NULL)
        printf("-> List destroyed\n");

    return 0;
}
