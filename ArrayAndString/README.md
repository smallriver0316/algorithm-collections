# Array and String

## String Compression

This codes produce simple compression against provided string.

For example, "aabcccccaaa" -> "a2b1c5a3".

If the result of compression is not shorter than an original string,
this codes will return the original string.

```bash
$ g++ string_compression.cpp
$ ./a.out
# input
# length of original string
11
# original string
aabcccccaaa
# result
a2b1c5a3
```

It checks length of the result before compression, because it takes too much cost to concatenate string, O(N2).

## Unduplicated String

It distinguishes whether a given string is composed of only unique characters.

The characters are assumed to be alphabets, lower-case characters.

```bash
$ g++ unduplicated_string1.cpp
$ ./a.out
# input is string
abcdefghijklmn
# result
True
# input
abcdea
# result
False
```

unduplicated_string2.cpp uses bitwise operation.

It assumes lower case alphabet string as input.
After changed it into number, bit shifted values by it must have different bit position if they are unique.

```bash
$ g++ unduplicated_string2.cpp
$ ./a.out
# input is string
abcdefghijklmn
# result
True
# input
abcdea
# result
False
```

## Permutated String

When two strings given, it distinguishes whether one is permutattion of another.

```bash
$ g++ permutated_string.cpp
$ ./a.out
# input
abcdefg
gfedcba
# result
True
```

## URLify

It **_replaces_** blank with "%20" in a given string.
(Not just output the string which the blanks are replaced.)

It assumes that the given string has blanks at the end in order to have enough space for replacement.
And the length of the string which excludes the blanks at the end is also given.

```bash
$ g++ urlify.cpp
$ ./a.out
# input
# string is "Mr John Smith    "
Mr John Smith
# length of string without the length of blanks at the end
13
# result
Mr%20John%20Smith
```

## Permutated Palindrome

It distinguish whether a given string is permutation of palindrome.

```bash
$ g++ permutated_palindrome1.cpp
$ ./a.out
# input
Tact Coa
# result; permutation is tacocat or atcocta
True
```

permutated_palindrome2.cpp uses hash table.
permutated_palindrome3.cpp uses bit operation.

## One Edit Away

It assumes there are 3 ways to edit string, insert, delete, and replace of a character.
And it can do only one edition at a time.

It distinguishes whether two given strings become equal after one edition or none.

```bash
$ g++ one_edit_away1.cpp
$ ./a.out
# input is two string
pale
ple
# result
True
```

one_edit_away1.cpp uses LCS(the longest common subsequence).
It is a kind of dynamic programming.

one_edit_away2.cpp is just compare two strings but the functional order is O(N).

## Rotation of Matrix

It rotates N x N matrix with 90-degree.

```bash
$ g++ rotate_matrix.cpp
$ ./a.out
# input
# initial input is number of N of N x N matrix
4
# second input is matrix
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
# result
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
```

The functional order is O(N2), because this program must be access each element in the matrix.

## Set zeros in Matrix

When a given M x N matrix has a zero element, it sets zeros to all elements in the columns and rows including the element.

```bash
$ g++ zero_inline2.cpp
$ ./a.out
# input
# initial inputs are M and N of M x N matrix
4 5
# second input is matrix
1 2 0 3 9
3 4 9 2 1
2 0 3 9 7
3 9 7 3 1
# result
0 0 0 0 0
3 0 0 2 1
0 0 0 0 0
9 0 0 9 9
```

zero_inline1.cpp is simple. It takes notes of zero elements' position in vector.
It converts the matrix with the notes.

But zero_inline2.cpp is more efficient in memory and performance.
It takes notes into the matrix itself, its first row and first column.

## Rotated String

Under following conditions, it distinguishes whether a string is rotation of another one.

- It can use a function of isSubstring, which distinguishes whether one string is substring of another.
- It can use isSubstring only one time.

For example, these strings are rotated of each other.

1. waterfront
2. ontwaterfr

```bash
$ g++ rotated_string.cpp
$ ./a.out
# inputs are two strings
waterbottle
erbottlewat
# result
True
```

isSubstring probably takes O(N1 + N2) of functional order, N1 and N2 are the length of each string.
Otherwise, it uses concatenation of string, so the functional order is O(N), which is required for concatenation.
