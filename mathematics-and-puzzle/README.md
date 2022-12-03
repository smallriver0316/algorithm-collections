# Mathematics and Puzzle

## Sieve of Elatosthenes

This is an algorithm to list up prime numbers.

It picks up a number and deletes numbers which can be devided by it.
Picking up from 0 to the target num, but actually from 2.

So, remained numbers must be prime.

```bash
$ g++ sieve_of_eratosthenes.cpp
$ ./a.out
# input is target number(max number)
50
# results are prime numbers between 0 and the max number
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
```
