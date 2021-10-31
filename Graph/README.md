# Graph

## Depth First Search

It outputs start and end timestamps against each vertex of a given graph when depth first search.

The graph is an oriented graph.
Vertices of the given graph have numbers which start from 1 to n and they are sequential.

In depth first search, start timestamp will be the time when the search tracer visits the veritex for the fist time,
and end timestamp will be the time when the tracer come back to the vertex after finished searching all of the adjacent vertices.

Timestamp is incremented sequentially one by one.

```bash
$ g++ depth_first_search.cpp
$ ./a.out
# initial input is number of vertex
6
# second input is adjacent list of graph
# vertex number, number of adjacent vertices, adjacent vertex(v1, v2, ...)
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

# result
# vertex number, timestamps(start, end)
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6
```

## Breadth First Search

It outputs distance from the first vertex to each vertex in a given graph.

The graph is an oriented graph.
Vertices of the given graph have numbers which start from 1 to n and they are sequential.

```bash
$ g++ breadth_first_search.cpp
$ ./a.out
# initial input is number of vertex
4
# second input is adjacent list of graph
# vertex number, number of adjacent vertices, adjacent vertex(v1, v2, ...)
1 2 2 4
2 1 4
3 0
4 1 3

# result
# vertex number, distance from the first vertex
1 0
2 1
3 2
4 1
```
