# Sorting

## Insertion Sort

It sorts a given array in ascending order with insertion sort.

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

It sorts a given array in ascending order with insertion with bubble sort.

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

It sorts a given array in ascending order with selection sort.

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

It sorts a given array in ascending order with shell sort.

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
