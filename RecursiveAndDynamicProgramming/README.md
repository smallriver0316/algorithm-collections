# Recursive and Dynamic Programming

## Exhaustive Search

It determins if it is possible to create target numbers from sum of several elements in given array.

```bash
$ g++ exhaustive_search1.cpp
$ ./a.out
# initial input is number of array elements
5
# second input are array elements
21 10 7 5 1
# third input is number of target numbers
4
# forth inputs are target numbers
2 17 4 8
# result
no
yes
no
yes
```

exhaustive_search1 is implemented with recursive processing.
On the other hand, exhaustive_search2 uses dynamic programming.

```bash
$ g++ exhaustive_search2.cpp
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

## Koch Curbe

It outputs each points of koch curbe.

Koch curbe has vertices which increase with the depth.

```bash
$ g++ koch_curve.cpp
$ ./a.out
# input is depth
2
# results are vertices of koch curbe
0.00000000 0.00000000
11.11111111 0.00000000
16.66666667 9.62250449
22.22222222 0.00000000
33.33333333 0.00000000
38.88888889 9.62250449
33.33333333 19.24500897
44.44444444 19.24500897
50.00000000 28.86751346
55.55555556 19.24500897
66.66666667 19.24500897
61.11111111 9.62250449
66.66666667 0.00000000
77.77777778 0.00000000
83.33333333 9.62250449
88.88888889 0.00000000
100.00000000 0.00000000
```
