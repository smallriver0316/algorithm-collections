# Array and String

## String Compression

This codes produce simple compression against provided string.

For example, "aabcccccaaa" -> "a2b1c5a3".

If the result of compression is not shorter than an original string,
this codes will return the original string.

```bash
$ g++ string_compression.cpp
$ ./a.out
11 # length of original string
aabcccccaaa
# result
a2b1c5a3
```

It may be better to identify the length of compressed string before compression and to allocate memory for it.
