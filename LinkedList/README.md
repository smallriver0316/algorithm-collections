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

## Count From End

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

This program also uses runner technique, so its performance cost is O(N).

## Delete Node

It deletes nodes in single oriented linked list.

```bash
$ g++ delete_node.cpp
$ ./a.out
# input
# first input is number of nodes
5
# second inputs are nodes of linked list
1 2 3 4 5
# third input is key of node to be deleted
4
# result
1 2 3 5
```

## Partition

It moves nodes the key of which is less than a given pivot value to left side against the pivot in single oriented linked list.
But it is not necessary to sort nodes in ascending order.

```bash
$ g++ partiion.cpp
$ ./a.out
# input
# first input is number of nodes
7
# second inputs are nodes of linked list
3 5 8 5 10 2 1
# third input is value of pivot
5
# result
3 2 1 5 8 5 10
```

## Addition

It calculates sum of two numbers that are represented single oriented linked list.

The each digit in the number will be one node of linked list,
so the key of node must be single digit,
and arranged from small digit.

For example, 714 is 4->1->7.

The output of this program is also represented in the same way.

```bash
$ g++ addition1.cpp
$ ./a.out
# first input is digit of the first number
3
# second input is linked list of the first number
# this reporesents 617(7->1->6).
7 1 6
# third input is digit of the second number
3
# forth input is linked list of the second number
# this represents 295(5->9->2).
5 9 2

# result
# this represents 912(2->1->9).
2 1 9
```
