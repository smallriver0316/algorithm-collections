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

## Adjacent Number

Given an integer, this program outputs the next and the previous number against it.
But these outputs must have the same number of "1" bits.

```bash
$ g++ adjacent_number1.cpp
$ ./a.out
# input number (10 = 1010b)
10
# result
# 12 = 1100b
Upside: 12
# 9 = 1001b
Downside: 9
```

adjacent_number2.cpp tries to solve this problem with more arithmetic method.

## Bit Conversion

When two integer given, this program calculates how many bits are required to convert one to another.
It means how many differences there are between the two intergers in bit sequence.

This operation is very easy,
so here implements various methods to solve this problem.

```bash
$ g++ bit_conversion.cpp
$ ./a.out
# first inptus are two intergers
29 15
# results from each implementations
2
2
2
2
```

## Exchange of Bit Pair

This program trys to exchange two bits in a pair with the fewest operations possibly.

Here, the pair means pair of even bit and odd bit,
for example, 1st and 2nd bit, 3rd bit and 4th bit, ....

```bash
$ exchange_bit_pair1.cpp
$ ./a.out
# input
34173
# output bit sequence of input
input: 1000010101111101
# result of exchange
19134
# bit sequence after exchanged
output: 100101010111110
```

exchange_bit_pair2.cpp uses a more effective way than exchange_bit_pair1.cpp.
It executes only 5 operations to solve this problem.

## Draw Line

This program draw a horizontal line in a screen.

The screen colors are only black and white,
and the all pixels are stored as byte array of single dimension.
1 byte contains 8 pixels.

The width of screen must be multiple of 8.
So, pixels won't be wrapped at the middle of byte.

In this situation, this program draw a line from (x1, y) to (x2, y).

Here, the number of pixels are set as 320.

```bash
$ draw_line.cpp
$ ./a.out
# input; width, x1, x2, y
32 5 25 6
# result
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000111111111111111111111000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
```
