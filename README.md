# Linked Lists

## Overview

This C module implements doubly-linked lists, and a variety of operations to perform on them. 

### Data Types

Each node in the list holds one element of signed integer data. 

### List Operations

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

### Planned Features for Future Release

- Exploring the possibility of making the data type dynamic, giving the user the ability to speicify what data type the list will hold (int, long, float, double, char, char*).

## Usage

### Declaring a list variable in your .c file

`List *list_name = NULL`

### Operations

`list_name = create_list()`

Returns the newly created, empty list of type List\*. No arguments taken.

---

`append_list(list_name, data)`

No return. Arguments taken: list to append of type List\*, data to append of type int.

---

`prepend_list(list_name, data)`

No return. Arguments taken: list to prepend of type List\*, data to prepend of type int.

---

`list_insert(list_name, index, data)`

No return. Arguments taken: list into which to insert of type List\*, index to insert at of type int, data to insert of type int.

---

`list_swap(list_name, index1, index2)`

No return. Arguments taken: list in question of type List\*, the first index to swap of type int, and the second index to swap of type int.

---

`len_var = list_length(list_name)`

Returns the length of the list of type int. Arguments taken: the list in question of type List\*.

---

`list_name1 = list_cat(&list_name1, &list_name2)`

Returns a joined list of type List\*. Arguments taken: the address of the first list, and the address of the second list, both of type List\*. This will join list_name2 onto the end of list_name1.  

---

`reverse_list(list_name)`

No return. Arguments taken: the list in question of type List\*.

---

`count_var = count_value(list_name, key)`

Returns the number of times the key appears in the list of type int. Arguments taken: the list in quesiton of type List\*, and the search key of type int. 

---

`list_sort(list_name)`

No return. Arguments taken: the list in question of type List\*. 

---

`print_index(list_name, index)`

No return. Arguments taken: the list in question of type List\*, and the index to print of type int.

---

`print_list(list_name)`

No return. Arguments taken: the list in question of type List\*.

---

`print_list_reverse(list_name)`

No return. Arguments taken: the list in question of type List\*.

---

`delete_head(list_name)`

No return. Arguments taken: the list in question of type List\*.

---

`delete_tail(list_name)`

No return. Arguments taken: the list in question of type List\*.

---

`delete_index(list_name, index)`

No return. Arguments taken: the list in question of type List\*, and the index to delete of type int

---

`delete_all_value(list_name, key)`

No return. Arguments taken: the list in question of type List\*, and the search key to delete of type int

---

`list_name = destroy_list(list_name)`

Returns a NULL List\*. Arguments taken: the list to destroy of type List\*. 
