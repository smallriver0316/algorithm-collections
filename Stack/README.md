# Stack

## Reverse Polish Notation

This is example implementation of stack.

Input operands and operators as Reverse Polish Notation.

For example, this is equal to `(1 + 2) * (3 - 4)`

```bash
$ g++ reverse_polish_notation.cpp
$ ./a.out
# input
1 2 + 3 4 - *
# result
-3
```

## Multiple Stack

It handles 3 stacks in one array.

There are two ways of implemetation,
one is the case of using array of fixed size,
another is one of using array of variable size.

```bash
$ g++ fixed_multiple_stacks.cpp
$ ./a.out
# first input is number of items to be stacked
10
# second inputs are pair of stack index and item to be stacked
0 1
1 2
2 3
0 4
1 5
2 6
0 7
1 8
2 9
0 1
# results, items in each stack, obtained by pop()
1 7 4 1
8 5 2
9 6 3
```

In variable_multiple_stacks.cpp, total size of stack capacity is set to 15.
The number of stacks is 3, so capacity of each stack has 5 as default size.

Following is demonstration that the capacity of each stack can be changed within total capacity.

```bash
$ g++ variable_multiple_stacks.cpp
$ ./a.out
# first input is number of items to be stacked
15
# second inputs are pair of stack index and item to be stacked
0 1
0 2
0 3
0 4
0 5
1 6
1 7
1 8
1 9
1 10
2 11
2 13
2 14
0 15
0 16
# results, items in each stack, obtained by pop()
16 15 5 4 3 2 1
10 9 8 7 6
14 13 11
```

## Stack with Minimum Value

It is implementation of stack which returns the minimum value.
The performance cost to returning minimum value must be O(1).

```bash
$ g++ stack_with_min.cpp
$ ./a.out
# first input is the number of items to be stacked
10
# second inputs are the items
8 3 9 4 2 7 3 4 6 1
# result
# these are minimum values when execuse pop() of stack to the last.
1
2
2
2
2
2
3
3
3
8
```

## Set of Stacks

It is implementation of stack of stacks.

When stacking and make one stack full, this program creates a new stack instance.
Each stack is also stacked.

This is demonstration of stacking stack.
The capacity of a stack is 5, so stacking 8 items creates another stack instance.

```bash
$ g++ set_of_stacks.cpp
$ ./a.out
# first input is number of stacked items
8
# second inputs are stacked items
1 2 3 4 5 6 7 8
# result, items obtained by pop()
8 7 6 5 4 3 2 1
```

## Queue composed of Stack

It is implementation of queue with stack.
It is allowed to use two stacks to implement the queue.

```bash
$ g++ queue.cpp
$ ./a.out
# first input is number of input items
10
# second inputs are pairs of command and item, but dequeue command doesn't have paired item
# commands are only enqueue and dequeue
enqueue 2
enqueue 8
enqueue 6
dequeue
dequeue: 2
enqueue 3
enqueue 1
enqueue 3
dequeue
dequeue: 8
enqueue 5
enqueue 7
# result, items obtained by dequeue()
6 3 1 3 5 7
```

## Sort Stack

It is implementation of sorting stack.

This stack must have sorted items in ascending order,
so the top item must be the least one.

Furthermore, in order to sort it, it is allowed to use only another stack.

```bash
$ ./sort_stack1.cpp
$ ./a.out
# first input is number of stacked items
10
# second inputs are stacked items
5 8 3 7 5 1 2 9 4 6
# result, items obtained by pop()
1 2 3 4 5 5 6 7 8 9
```

sort_stack2.cpp executes sorting when input stacked items.
But the algorithm is same as sort_stack1.cpp in essence.
