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
