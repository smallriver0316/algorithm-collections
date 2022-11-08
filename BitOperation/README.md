# Bit Operation

## Insert

This program insert a bit sequence to another one.

N is the bit sequence which accept insertion.
M is one which is inserted.

And inserted position is expressed with two parameters, i and j.
They specifies bit position in N and the difference between i and j must be equal to the length of M.

```bash
$ g++ insert.cpp
$ ./a.out
# first inputs are N and M
65 9
# second inputs are insert position; i, j
2 5
# bit expression of N and M.
N: 1000001
M: 1001
# result
1100101
```
