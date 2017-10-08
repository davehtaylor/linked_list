# Linked Lists

This C module implements doubly-linked lists, and a variety of operations to perform on them. 

**Data Types**

Each node in the list holds one element of signed integer data. 

**List Operations**

- Creating the list
- Appending elements
- Prepending elements
- Insert element at arbitrary point
- Swap two elements
- Returning the list length
- Concatenating two lists
- Reversing the list
- Counting occurrences of a specific value
- Sorting the list
- Printing specific element in the list
- Printing all elements in the list forward or in reverse
- Deleting the first node
- Deleting the last node
- Deleting arbitrary elements
- Deleting all occurrences of a specific value
- Destroying the list

**Planned Features for Future Release**

- Exploring the possibility of making the data type dynamic, giving the user the ability to speicify what data type the list will hold (int, long, float, double, char, char*).

## Usage

- create_list(void)
>Returns the newly created, empty list of type List\*. No arguments taken. 

- append_list(list, data)
>No return. Arguments taken: list to append of type List\*, data to append of type int.

- prepend_list(list, data)
>No return. Arguments taken: list to prepend of type List\*, data to prepend of type int.

- list_insert(list, index, data)
>No return. Arguments taken: list into which to insert of type List\*, index to insert at of type int, data to insert of type int.

- list_swap(list, index1, index2)
>No return. Arguments taken: list in question of type List\*, the first index to swap of type int, and the second index to swap of type int.

- list_length(list)
>Returns the length of the list of type int. Arguments taken: the list in question of type List\*.

- list_cat(destination, source1, source2)
>Returns a newly joined list of type List\*. Arguments taken: the destination list, the first source list, the second source list, all of type List\*. It is recommended to assign the return value of this function to a NULL list as destination. It will destroy any filled list passed to it as a destination. 

- reverse_list(list)
>No return. Arguments taken: the list in question of type List\*.

- count_value(list, key)
>Returns the number of times the key appears in the list, of type int. Arguments taken: the list in quesiton of type List\*, and the search key of type int. 

- list_sort(list)
>No return. Arguments taken: the list in question of type List\*. 

- print_index(list, index)
>No return. Arguments taken: the list in question of type List\*, and the index to print of type int.

- print_list(list)
>No return. Arguments taken: the list in question of type List\*.

- print\_list\_reverse(list)
>No return. Arguments taken: the list in question of type List\*.

- delete_head(list)
>No return. Arguments taken: the list in question of type List\*.

- delete_tail(list)
>No return. Arguments taken: the list in question of type List\*.

- delete_index(list, index)
>No return. Arguments taken: the list in question of type List\*, and the index to delete of type int

- delete\_all\_value(list, key)
>No return. Arguments taken: the list in question of type List\*, and the search key to delete of type int

- destroy_list(list)
>Returns a NULL List\*. Arguments taken: the list to destroy of type List\*. 
