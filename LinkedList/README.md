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
7 # the number of input commands
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