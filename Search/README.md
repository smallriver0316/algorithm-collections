# Search

## Search in Rotated Array

This program search a specified item in a rotated array.

This array is originally sorted, but after that rotated several times.

For example, find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}.

From this example, it figures out that rotated parts in the array keep the order.

```bash
$ g++ search_rotated_array.cpp
$ ./a.out
# first input is number of array
12
# second input is items of array
15 16 19 20 25 1 3 4 5 7 10 14
# third input is target item
5
# result
Target Index: 8
```

This problem is solved by application of binary search, but the problem itself seems not to be good.

It does not define how to rotate an array.
If rotations are done at random position,
the array will be also arranged randomly and the assumption, the array is originally sorted, will be nothing to work.

The performance cost of this algorithm will be O(logN) at the best, because of binary search, but O(N) at the worst.

## Search in Array of Unknown Size

This problem assumes an array whose function called elementAt(i) can output an item of specified index and whose size is unknown.

In this situation, this program find index of specified target value.

```bash
$ g++ search_unknown_size_array.cpp
$ ./a.out
10
3 7 9 13 16 18 20 24 29 35
20
6
```
