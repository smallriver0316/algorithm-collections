# Sorting

## Insertion Sort

It sorts a given array in ascending order with Insertion Sort.

Furthermore, it outputs the rearranged array in the each process.

```bash
$ g++ insertion_sort.cpp
$ ./a.out
# initial input is number of elements
6
# second input is array
5 2 4 6 1 3

# result; it is written in each process of insertion sort.
5 2 4 6 1 3
2 5 4 6 1 3
2 4 5 6 1 3
2 4 5 6 1 3
1 2 4 5 6 3
1 2 3 4 5 6
```

Functional order of Insertion Sort is O(N2) at worst, it is when a given array is initially descending order.

But when it is initially ascending order, there happens no replacement of elements.
In that case, the order becomes O(N).

## Bubble Sort

It sorts a given array in ascending order with insertion with Bubble Sort.

Furthermore, it outputs the number of replacements in the sorting.

```bash
$ g++ bubble_sort.cpp
$ ./a.out
# initial input is number of elements
5
# second input is array
5 3 2 4 1

# result
# the first is sorted array
1 2 3 4 5
# the second is number of replacements in sorting.
8
```

Functional order of Bubble Sort is O(N2).

## Selection Sort

It sorts a given array in ascending order with Selection Sort.

Furthermore, it outputs the number of replacements in the sorting.

```bash
$ g++ selection_sort.cpp
$ ./a.out
# initial input is number of elements
6
# second input is array
5 6 4 2 1 3

# result
# the first is sorted array
1 2 3 4 5 6
# the second is number of replacements in sorting.
4
```

Functional order of Selection Sort is O(N2).

## Shell Sort

It sorts a given array in ascending order with Shell Sort.

Shell sort is an applied method of selection sort, which can sort quickly in the case that the given array is almost sorted.

```bash
$ g++ shell_sort.cpp
$ ./a.out
# initial input is length of given array
10
# second input is array
4 8 9 1 10 6 2 5 3 7

# result
# length of gap sequence in shell sort
2
# elements of gaps
1 4
# number of replacements
16
# sorted array
1 2 3 4 5 6 7 8 9 10
```

Functional order of Shell Sort is O(N3/4) ~ O(N2).

## Merge Sort

It sorts a given array in ascending order with Merge Sort.

Furthermore, it outputs the number of comparisons in the sorting.

```bash
$ g++ merge_sort.cpp
$ ./a.out
# initial input is length of given array
10
# second input is array
8 5 9 2 6 3 7 1 10 4

# result
# sorted array
1 2 3 4 5 6 7 8 9 10
# number of comparisons
34
```

In Merge Sort, functional order of dividing is O(logN), because an original array is devided into half repeatedly until only one element remained.
Additionally, order of merging is O(N).
As a result, functional order of Merge Sort is O(NlogN).

## Partition

It classifies elements of a given array with a target of partition.

The target is the last element of the given array.
Elements of less than the target are aligned to left side, and larger ones are to right side.

```bash
$ g++ partition.cpp
$ ./a.out
# initial input is length of given array
12
# second input is array
13 19 9 5 12 8 7 4 21 2 6 11

# result
# sorted array with highlighted partition
9 5 8 7 4 2 6 [11] 13 21 12 19
```

This operation is similar to Selection Sort.
The functional order is O(N).

## Quick Sort

It sorts a given array in ascending order with Quick Sort.

The given array is assumed to be list of cards,
which are composed of pairs of a character and a number.

Furthermore, it shows whether the sorting method is stable,
which means relative order of cards with same number and different character does not change.

```bash
$ g++ quick_sort.cpp
$ ./a.out
# initial input is length of array
6
# second input is cards, pairs of suit and number
D 3
H 2
D 1
S 3
D 2
C 1

# result
# whether result of sorting is Stable or Not Stable.
Not Stable
# sorted array
D 1
C 1
D 2
H 2
D 3
S 3
```

Quick Sort uses partition in sorting.
Functional order of partition is O(N).
Furthermore, all partitionings take O(logN).

So the functional Order of Quick Sort is O(NlogN).

## Stable Sort

This is to confirm the logic of determine whether sorting method is stable or not.

The logic is one that used in Quick Sort.

It can be confirmed by testing a result of Bubble Sort, which is known as stable sort.
In addiotion, it tests a result of Selection Sort.
From the two sorting results, confirm that isStable logic is valid.

```bash
$ g++ stable_sort.cpp
$ ./a.out
# initial input is length of array
5
# second input is cards, pairs of suit and value
H4 C9 S4 D2 C3

# result
# first result is of Bubble Sort
D2 C3 H4 S4 C9
# Bubble Sort is stable or not
Stable
# second result is of Selection Sort
D2 C3 S4 H4 C9
# Selection Sort is stable or not
Not Stable
```

## Counting Sort

It sorts a given array in ascending order with Counting Sort.

Counting Sort uses an array to record frequency of each element.
And this size is equal to the max number of elements.

The max size of the given array is 2000000.
So if try to create arrays of the size of int, segmentation fault will happen.

```bash
$ g++ counting_sort.cpp
$ ./a.out
# initial input is length of array
7
# second input is array
2 5 1 3 2 3 0

# result; sorted array
0 1 2 2 3 3 5
```

The functional order of Counting Sort is O(N + K),
K is the size of array to record frequency.

## Number of Inversion

Given an array, a1, a2, a3, ..., an,
when there are elements such as i < j and ai > aj,
it calls inversion.

This program counts the number of inversion.

It is equal to the number of swap in Bubble Sort,
but it takes too much operation cost because the functional order is O(N2).

```bash
$ g++ inversion.cpp
$ ./a.out
# initial input is length of array
6
# second input is array
5 3 6 2 1 4

# result: number of inversion
10
```

## Minimum Cost Sort

Assume there are several burdens of some weight,
and now try to sort them in ascending order of its weight.

Sorting takes cost.
When replacing burdens of weight a and b, it takes cost of (a + b).

In this case, this program calculates the minimum cost for sorting.

```bash
$ g++ minimum_cost_sort.cpp
$ ./a.out
# initial input is number of burdens
7
# second input is array of burdens' weight
4 3 2 7 1 6 5

# result: minimum cost of sorting
24
```

## Merge Sorted Arrays

This program merge two arrays which have already been sorted.

The first array is assumed that it has enough space to add the second array to the end.

This is application of merge sort's process.

```bash
$ merge_sorted_array.cpp
$ ./a.out
# initial input is number of items in first array
5
# second input is the first array
3 4 8 10 13
# third input is number of items in second array
3
# fourth input is the second array
6 11 25
# result
3, 4, 6, 8, 10, 11, 13, 25,
```

## Grouping Anagrams

Given array of strings, this program make strings of anagram arranged next to each other.

Here, given array includes strings of anagram, such as "acre", "crea", "care".

So in the result of this process, these three words must be arranged to next of each other.

```bash
$ g++ group_anagrams.cpp
$ ./a.out
# first input is number of strings
5
# second input is strings
race hoge fflls care acre
# result
fflls, hoge, race, care, acre,
```

## Rank Integer Sequence

This program rank numbers over reading a integer sequence.

Here, rank of integer X means how many times numbers that is less than X appeared.

So in this probrem, it is necessary to implement two functions,
one is track(), which is called to read a number,
and another is getRankOfNumber(), which is called to output rank of a given number.

```bash
$ g++ rank_integers1.cpp
$ ./a.out
# first input is length of integer sequence
9
# second input is integer sequence
5 1 4 4 5 9 7 13 3
# third input is number of getRankOfNumber() called
3
# fourth input is argument of getRankOfNumber()
1
# result of getRankOfNumber()
0
# argument of getRankOfNumber()
3
# result
1
# argument of getRankOfNumber()
4
# result
2
```
