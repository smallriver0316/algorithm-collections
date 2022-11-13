# Bit Operation

## Insert

This program insert a bit sequence to another one.

N is the bit sequence which accept insertion.
M is one which is inserted.

And inserted position is expressed with two parameters, i and j.
They specifies bit position in N and the difference between i and j must be equal to the length of M.

```bash
$ g++ insert1.cpp
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

## Binary Expression of Decimal Number

This program converts dicimal number into binary number expression.

The input decimal is double type and it must be in range from 0 to 1.

Furthermore, if the result cannot be expressed within 32 digits, the output will be "ERROR".

```bash
$ g++ binary_decimal1.cpp
$ ./a.out
# input: decimal number
0.625
# result: binary number
.101
```
