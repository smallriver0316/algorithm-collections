# Recursion

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

## Koch Curbe

It outputs each points of koch curbe.

Koch curbe has vertices which increase with the depth.
When the depth increases, each edge has 3 vertices and the length of new edges are same.

```txt
depth = 0      depth = 1
______    =>   __/\__
```

```bash
$ g++ koch_curbe.cpp
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

## Triple Steps

It assumes that a person can step up stairs by one, two, or three at once.

Under this condition, this algorithm calculates how many patterns there are in stepping up stairs.

The number of steps in the stairs will be given as input.

It will take O(3^N) as performance cost. So it will be improved by using memoization.

```bash
$ g++ triple_steps.cpp
$ ./a.out
# first input is the number of steps in stairs
10
# result
274
```

## Grid Walk

It assumes that a robot moves from the left-upper cell to the right-bottom one in r x c grid.

The robot can move only to right and down direction and several cells are not available.

Under these conditions, this program calculates the pass for the robot to reach the goal.

```bash
$ g++ grid_walking.cpp
$ ./a.out
# fist input is the number of rows and columns
3 3
# second input is the number of unavailable cells
2
# third input is coordinates of unavailable cells
1 0
1 2
# result
→ ↓ ↓ →
```

This algorithm save the cell which is stopped by once.
By this method, it takes O(rc) as performance cost.

## Magic Index

When there are array in which the all items are numbers, different from each other and sorted in ascending order,
here defines an index of Array\[i\] == i as magic index.

This program searches a magic number from a given array.

```bash
$ g++ magic_index1.cpp
$ ./a.out
# first input is size of array
7
# second input is array
-1 0 1 2 4 7 8
# result
4
```
