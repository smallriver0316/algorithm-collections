# Linked List

## Double Linked List

This codes represent implementation of basic double linked list.

The double linked list accepts following commands.

- insert x: add key x to the double linked list as the first node.
- delete x: delete a node of key x first in the double linked list.
- deleteFirst: delete the first node.
- deleteLast: delete the last node.

```bash
$ g++ double_linked_list.cpp
$ ./a.out
# input
# the number of input commands
7
# commands
insert 5
insert 2
insert 3
insert 1
delete 3
insert 6
delete 5
# result
6 1 2
```

## Unique Linked List

It removes duplicated elements from an unsorted linked list.

```bash
$ g++ unique_linked_list1.cpp
$ ./a.out
7
1 2 3 2 4 1 8
1 2 3 4 8
```
