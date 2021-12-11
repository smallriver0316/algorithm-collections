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
# input
# initial input is number of node in linked list
7
# second inputs are nodes in linked list
1 2 3 2 4 1 8
# result
1 2 3 4 8
```

unique_linked_list1.cpp takes O(N) as functional order, but requires O(N) as memory cost.

unique_linked_list2.cpp uses runner method for linked list, which is just twice loop for linked list.
It takes O(N2) as functional order, but requires only O(1) as memory cost.

## Count From Last

It output k-th node from end of single oriented linked list.

```bash
$ g++ count_from_end.cpp
$ ./a.out
# input
# first input is number of node
5
# second inputs are nodes of linked list
5 4 3 2 1
# third input is k
3
# result
3
```
