# Stack and Queue

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
# firstinput is number of items to be stacked
10
# seconds inputs are pair of stack index and item to be stacked
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

## Stack with minimum value

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
