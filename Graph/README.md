# Graph

## Depth First Search

It outputs start and end timestamps against each vertex of a given graph when depth first search.

In depth first search, connected vertices are visited preferentially from one to the next.
After all connected are visited, shift the next unvisited vertices.
These processes are achieved with Stack.

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
# initial input is number of vertices
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

In breadth first search, vertices connected directly to the target vertex are visited preferentially.
After all of them are visited, shift the target to one of them.
These processes are acheived with Queue.

## Connected Components

It outputs whether given pairs of vertices in Graph are reachable.

The graph is bi-directional.
Vertices of the given graph have numbers which start from 0 to (n-1) and they are sequential.

```bash
$ g++ connected_components.cpp
$ ./a.out
# initial input is number of vertices and number of connections
10 9
# second input is connection of vertices
0 1
0 2
3 4
5 7
5 6
6 7
6 8
7 8
8 9
# third input is number of pairs which is asked to be reachable
3
# pair of vertices which is asked to be reachable
0 1
# result, they are reachable or not
yes
# same as above
5 9
yes
1 3
no
```
