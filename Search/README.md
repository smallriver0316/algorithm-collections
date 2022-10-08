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

If the specified index is larger than array size, elementAt(i) gives -1.

The array is also assumed to be sorted.
So all items in the array must be numbers greater than 0.

In this situation, this program find index of specified target value.

```bash
$ g++ search_unknown_size_array.cpp
$ ./a.out
# first input is number of items in the array
10
# second input is items in the array
3 7 9 13 16 18 20 24 29 35
# third input is target item
20
# result
6
```

## Search in Chinky Array

This program finds index of specified target in a given array.

This array is assumed to be sorted, but it has several chinks of null characters.

For example,

{"at", "", "", "", "ball", "", "", "car", "", "", "dad"}

```bash
$ g++ search_chinky_array.cpp
$ ./a.out
# first input is number of words in array
4
# second input is set of word and number of null characters followed the word
at 3
ball 2
car 2
dad 2
# array resulted from the above input
"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "",
# fourth input is target word
ball
# result
Target index is 4 th index.
```

## Search Redundant Numbers

This algorithm finds redundant numbers from an array.

The array has numbers of 1 ~ N as its elements.
N is 3200 at largest.
The array has redundant numbers and its size is unknown.

Furthermore, there is a limitation that this algorithm can use memory of 4KB or less.

This program make an array of specified size, and composed of random numbers of 1 ~ 3200.
And it outputs redundant numbers in it.

```bash
$ g++ search_redundant_numbers.cpp
$ ./a.out
# input is size of array
3210
# result
17713
30544
21333
31651
27219
5250
6068
31825
8232
25533
22662
20880
11529
10482
14245
648
18548
17429
4693
21379
...
```
