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

## Best Inversion Position

Given an integer, this program inverts only one bit from 0 to 1 in it,
and outputs the maximum length of consecutive 1s.

For example, 1775.

- binary digit of 1775 is 11011101111
- result is 8

```bash
$ g++ inversion_position1.cpp
$ ./a.out
# input; 1101110111
1775
# result
8

$ ./a.out
# input; 1011001011001
5721
# result
4
```

All of programs takes O(bit length) as performance cost, because they must scan all bit.

inversion_position1.cpp records positions of 0 and calculates the longest consecutive 1s from them.
So, it takes O(count of 0 bit) as memory cost.

inversion_position2.cpp records lengthes of each consecutive same bits(0 or 1).

inversion_position3.cpp is smarter than others.
It scans bit sequence and keeps current length of 1 bit and previous one.
It takes O(1) as memory cost.
