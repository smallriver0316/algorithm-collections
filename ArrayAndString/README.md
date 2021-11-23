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

It may be better to identify the length of compressed string before compression and to allocate memory for it.

## Unduplicated String

It distinguishes whether a given string is composed of only unique characters.

The characters are assumed to be alphabets, lower-case characters.

```bash
$ g++ unduplicated_string1.cpp
$ ./a.out
# input is string
abcdefghijklmn
# result
Unique
# input
abcdea
# result
Not Unique
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
Unique
# input
abcdea
# result
Not Unique
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
Permutated
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
