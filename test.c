/* Test cases for linked list module */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(void)
{
    List *test_list1 = NULL;
    List *test_list2 = NULL;
    List *test_list3 = NULL;
    List *test_joined = NULL; 
    List *list = NULL;
    int i, len, count;
    srand(time(NULL));

    // Test non-existent list
    printf("-> Testing list before creation\n");
    print_list(list);

    // Create list
    printf("\n-> Creating list\n");
    list = create_list();
    test_list1 = create_list();
    test_list2 = create_list();
    test_list3 = create_list();
    test_joined = create_list();

    // Append
    printf("\n-> Appending '95'\n");
    append_list(list, 95);
    print_list(list);
    
    // Test delete head with only one element
    printf("\n-> Deleting head\n");
    delete_head(list);
    print_list(list);
    
    // List length
    printf("\n-> List length\n");
    len = list_length(list);
    printf("List is %d nodes long\n", len);

    // Append
    printf("\n-> Appending '2501'\n");
    append_list(list, 2501);
    print_list(list);

    // Prepend
    printf("\n-> Prepending '2095' and '95'\n");
    prepend_list(list, 2095);
    prepend_list(list, 95);
    print_list(list);

    // Append a bunch
    printf("\n-> Appending a bunch of random values\n");
    for (i = 0; i < 45; i++)
    {
        append_list(list, (rand() % 20 + 1));
    }
    print_list(list);

    // Insert
    printf("\n-> Inserting '10' at index 2\n");
    list_insert(list, 2, 10);
    print_list(list);

    // Swap
    printf("\n-> Swapping indeces 0 and 5\n");
    list_swap(list, 0, 5);
    print_list(list);

    // Print specific element
    printf("\n-> Printing index 5\n");
    print_index(list, 5);

    // Print list in reverse
    printf("\n-> Printing list in reverse order\n");
    print_list_reverse(list);

    // Actually reverse the list
    printf("\n-> Reversing the list\n");
    reverse_list(list);
    print_list(list);

    // List length
    printf("\n-> List length\n");
    len = list_length(list);
    printf("List is %d nodes long\n", len);
    
    // Count occurrences of a particular element
    printf("\n-> Counting occurrences of '95' in list\n");
    count = count_value(list, 95);
    printf("'95' appears %d times\n", count);

    // Sort list
    printf("\n-> Sorting list\n");
    list_sort(list);
    print_list(list);

    // Delete occurences of a particular element
    printf("\n-> Deleting all occurences of '95' in list\n");
    delete_all_value(list, 6);
    print_list(list);

    // Delete arbitrary element
    printf("\n-> Deleting index 1\n");
    delete_index(list, 1);
    print_list(list);

    // Delete head
    printf("\n-> Deleting head\n");
    delete_head(list);
    print_list(list);

    // Delete tail
    printf("\n-> Deleting tail\n");
    delete_tail(list);
    print_list(list);
    
    // Destroy it
    printf("\n-> Destroying list\n");
    list = destroy_list(list);
    print_list(list);

    // Test joining two lists
    printf("\n-> Making two new lists. Here they are:\n");
    for (i = 0; i < 10; i++)
    {
        append_list(test_list1, (rand() % 20 + 1));
    }   
    for (i = 0; i < 10; i++)
    {
        append_list(test_list2, (rand() % 20 + 1));
    }   
    print_list(test_list1);
    print_list(test_list2);

    printf("\n-> Concatenating the two new lists\n");
    test_joined = list_cat(test_joined, test_list1, test_list2);
    print_list(test_joined);

    // Making a new list to test deleting a uniform list
    printf("\n-> Making a new list of all 7\n");
    for (i = 0; i < 10; i++)
    {
        append_list(test_list3, 7);
    }
    print_list(test_list3);

    // Delete all values
    printf("\n-> Deleting all occurences of 7\n");
    delete_all_value(test_list3, 7);
    print_list(test_list3);

    return 0;
}
