# Dynamic Programming

## Exhaustive Search

It solves the same problem as the one implemented in Recursion.

When an array is geven, it determins if it is possible to create target numbers from sum of several elements in the array.

```bash
$ g++ exhaustive_search.cpp
$ ./a.out
5
21 10 7 5 1
4
2 17 4 8
no
yes
no
yes
```

## Fibonacci Number

It returns fibonacci number when the rank is specified.

```bash
$ g++ fibonacci_number.cpp
$ ./a.out
# input is rank of fibonacci numbers
10
# result
89
```

## The Longest Common Subsequence

It solves the length of the longest common subsequence (LSC) between two strings.

In the following case, LCS is "bdab", so the length is 4.

```bash
$ g++ longest_common_subsequence.cpp
$ ./a.out
# inputs are two strings
abcbdab
bdcaba
# result is the length of LCS
4
```

## Matrix Chain Multiplication

It solves Matrix-Chain Multiplication problem.

For example, when multiplying three matrices, like M1 \* M2 \* M3, the number of total multiplications varies in accordance with the order.
In this case, there are two patterns of order.

- M1 \* (M2 \* M3)
- (M1 \* M2) \* M3

This program figures out the minimum number of the multiplications.

```bash
$ g++ matrix_chain_multiplication.cpp
$ ./a.out
# initial input is number of matrix
6
# followings are number of rows and columns of each matrix
30 35
35 15
15 5
5 10
10 20
20 25
# result
15125
```

## Triple Steps

This is a improved program of one in Recursion section with memoization.

It assumes that a person can step up stairs by one, two, or three at once.

Under this condition, this algorithm calculates how many patterns there are in stepping up stairs.

The number of steps in the stairs will be given as input.

Because of memoization, the memory cost is only O(3) and performance cost is O(N).

```bash
$ g++ triple_steps.cpp
$ ./a.out
# first input is the number of steps in stairs
10
# result
274
```

## Grid Walk

This program is proto-type of one in Recursion section.

```bash
$ g++ grid_walking.cpp
$ ./a.out
# fist input is the number of rows and columns
3 3
# second input is the number of unavailable cells
2
# third input is coordinates of unavailable cells
1 0
1 2
# result
→ ↓ ↓ →
```

## Recursive Multiplication

This is the same problem as one in Recursion directory.

This program calculates product, result of multiplication without multiplication.
Addition, Subtraction, and bit operation are allowed to use.

It is the version using dynamic programming, inproved from recursive_multiplication2.cpp in Recursion directory.

```bash
$ g++ recursive_multiplication.cpp
$ ./a.out
# first inputs are operands
17 23
# result
result: 391
```

## Coins

This is an improved program of Recursion/coins2.cpp.

There are 4 types of coins, 1 cent, 5 cent, 10 cent and 25 cent.

Here, number of each of them is outside of thinking, so much enough are there.

This program outputs number of cases to make a given price with these coins.

```bash
$ g++ coins.cpp
$ ./a.out
# input is price
26
# result
13
```

## Pile Boxes

This program solves a problem to pile boxes under following conditions.

- Box has paramers of width, height, depth.
- All boxes cannot be rotated.
- A box can be put on a box whose width, height, and depth are all larger than itself.

Under this condition, this program calculates the maximum height of piled boxes.

This can be solved by recursion, but its performance is same as non-recursion method.
It will be O(n2), n is the number of boxes.

So dynamic programming is required to make faster to solve it.

```bash
$ g++ pile_boxes.cpp
$ ./a.out
4
4 8 9
1 2 3
2 4 7
1 9 6
14
```

## Boolean Expression

This program solves how many patterns there are to insert brackets into string of boolean expression.

The boolean expression is composed of 1(true), 0(false), &(AND), |(OR) and ^(XOR).

Also the answer of it, (or true/false), is given with the string.

For example, "1^0|0|1" and false.

- (1)^((0|0)|1) -> false
- (1)^(0|(0|1)) -> false
- (1^0)|(0|1) -> true
- (1^0|0)|(1) -> true

In this case, the number of patterns is 2.

```bash
$ g++ boolean_expression.cpp
$ ./a.out
# first input is string of boolean expression
0&0&0&1^1|0
# second input is answer of boolean expression
true
# result
patterns: 10
```
