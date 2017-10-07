/* Test cases for linked list module */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(void)
{
    List *test_list1 = NULL; 
    List *test_list2 = NULL;
    List *test_joined = NULL; 
    List *list = NULL;
    int i, len, count;
    srand(time(NULL));

    // Test non-existent list
    printf("-> Testing null list\n");
    print_list(list);

    // Create list
    test_list1 = create_list();

    // Create list
    test_list2 = create_list();

    // Create list
    test_joined = create_list();

    // Create list
    printf("\n-> Creating list\n");
    list = create_list();

    // Append
    printf("\n-> Appending\n");
    append_list(list, 95);
    print_list(list);

    // Append
    printf("\n-> Appending\n");
    append_list(list, 2501);
    print_list(list);

    // Prepend
    printf("\n-> Prepending\n");
    prepend_list(list, 2095);
    print_list(list);

    // Prepend
    printf("\n-> Prepending\n");
    prepend_list(list, 95);
    print_list(list);

    // Prepend
    printf("\n-> Prepending\n");
    prepend_list(list, 867530);
    print_list(list);

    // Append a bunch
    printf("\n-> Appending a bunch of random values\n");
    for (i = 0; i < 45; i++)
    {
        append_list(list, (rand() % 20 + 1));
    }
    print_list(list);

    // Append
    printf("\n-> Appending\n");
    append_list(list, 95);
    print_list(list);

    // Append
    printf("\n-> Appending\n");
    append_list(list, 107);
    print_list(list);

    // Insert
    printf("\n-> About to insert 71 at index 2\n");
    list_insert(list, 2, 71);
    print_list(list);

    // Print specific element
    printf("\n-> About to print element 5\n");
    print_index(list, 5);

    // Print list in reverse
    printf("\n-> Attempting to print list in reverse order\n");
    print_list_reverse(list);

    // Actually reverse the list
    printf("\n-> About to actually reverse the list\n");
    reverse_list(list);
    print_list(list);

    // List length
    printf("\n-> About to count the elements in list\n");
    len = list_length(list);
    printf("List is %d nodes long\n", len);
    
    // Count occurrences of a particular element
    printf("\n-> About to count occurrences of '95' in list\n");
    count = count_value(list, 95);
    printf("'95' appears %d times\n", count);

    // Delete occurences of a particular element
    printf("\n-> About to delete all occurences of '95' in list\n");
    delete_all_value(list, 95);
    print_list(list);

    // Delete arbitrary element
    printf("\n-> About to delete index 1\n");
    delete_index(list, 1);
    print_list(list);

    // Delete head
    printf("\n-> About to delete head\n");
    delete_head(list);
    print_list(list);

    // Delete tail
    printf("\n-> About to delete tail\n");
    delete_tail(list);
    print_list(list);
    
    // Destroy it
    printf("\n-> About to destroy list\n");
    list = destroy_list(list);
    if (list == NULL)
        printf("\n-> List destroyed\n");

    // Test joining two lists
    printf("\n-> Making two new lists\n");
    for (i = 0; i < 10; i++)
    {
        append_list(test_list1, (rand() % 20 + 1));
    }   
    for (i = 0; i < 10; i++)
    {
        append_list(test_list2, (rand() % 20 + 1));
    }   
    printf("\n-> Here's the two new lists:\n");
    print_list(test_list1);
    print_list(test_list2);
    printf("\n-> Here they are joined:\n");
    test_joined = list_cat(test_joined, test_list1, test_list2);
    print_list(test_joined);

    return 0;
}
