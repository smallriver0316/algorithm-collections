# Graph

## Depth First Search

This program outputs start and end timestamps against each vertex of a given graph when depth first search.

In depth first search, connected vertices are visited preferentially from one to the next.
After all connected vertices are visited, shift the next unvisited vertices.
This process is achieved with Stack.

The graph is an oriented graph.
Vertices of the given graph have numbers which start from 1 to n and they are sequential.

In depth first search, start timestamp is the time when the search tracer visits the vertex for the fist time,
and end timestamp is the time when the tracer comes back to the vertex after finished searching all of the adjacent vertices.

Timestamp is incremented sequentially one by one.

```bash
$ g++ depth_first_search.cpp
$ ./a.out
# initial input is number of vertex
6
# second input is adjacent list of graph
# vertex number, number of adjacent vertices, adjacent vertices(v1, v2, ...)
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

This program outputs distances from the first vertex to each vertex in a given graph.

The graph is an oriented graph.
Vertices of the given graph have numbers which start from 1 to n and they are sequential.

```bash
$ g++ breadth_first_search.cpp
$ ./a.out
# initial input is number of vertices
4
# second input is adjacent list of graph
# vertex number, number of adjacent vertices, adjacent vertices(v1, v2, ...)
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

This program outputs whether given pairs of vertices in Graph are reachable.

The graph is a non-oriented graph.
Vertices of the given graph have numbers which start from 0 to (n-1) and they are sequential.

```bash
$ g++ connected_components1.cpp
$ ./a.out
# initial input is number of vertices and number of connections
10 9
# second inputs are connections of vertices
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

connected_components2.cpp recieves an oriented graph as input.
The number of vertices are sequential from 1 to n.

```bash
$ g++ connected_components2.cpp
$ ./a.out
# first input is number of vertices
6
# second input is adjacent list of graph
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
# third input is number of questions
3
# pair of vertices which is asked to be reachable
4 5
# result, they are reachable or not
no
5 6
yes
1 5
yes
```

## Minimum Spanning Tree

This program calculates minimum spanning tree(MST) from a given weighted graph
and output the total weight of it.

Tree is graph which has no closed path, and tree with pathes to all the vertices is called spanning tree.
MST is one of which total weights of the edges become minumum value.

```bash
$ g++ minimum_spanning_tree1.cpp
$ ./a.out
# first input is number of vertices
5
# second input is adjacent list of graph, but the elements are weights of the edges
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1
# result, sum of weights in MST
5
```

minimum_spanning_tree2.cpp uses prim's algorithm.

```bash
$ g++ minimum_spanning_tree2.cpp
$ ./a.out
# first input is number of vertices
5
# second input is adjacent list of graph, but the elements are weights of the edges
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1
# result, sum of weights in MST
5
```

Both programs separate vertices into two group, ones inside MST and others outside MST,
and try to find minimum weight between them and to make a vertex of the minimum weight included into MST one by one.
Prim's algorithm forcuses ones outside MST.
It calculates minimum weight against each vertex outside MST to MST.

On the other hand, minimum_spannig_tree1.cpp forcuses vertices inside MST,
but the principle of the following processes is same.

Functional orders of them are roughly O(N2).

## Single Source Shortest Path

This program calculates minimum distance from vertex 0 to each vertex in a given graph.

The graph is an oriented graph with weight on the edges.
The vertices have numbers which start from 0 to (n-1) and they are sequential.
And there must be pathes from vertex 0 to each vertex.
In this question, distance between vertex 0 and another is sum of weights on the pathes.

Limitation is below.

```txt
1 <= n <= 100
0 <= weight on edge <= 100000
```

```bash
$ g++ single_source_shortest_path1.cpp
$ ./a.out
# first input is number of vertices
5
# second input is adjacent list of graph
# each node, number of the connections, adjacent node, weight of the edge, ...
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
# result, distance from node 0 to each node
0 0
1 2
2 2
3 1
4 3
```

single_source_shortest_path2.cpp uses Dijkstra's algorithm.
It is the same as minimum spanning tree (MST) in essence.

```bash
$ g++ single_source_shortest_path2.cpp
$ ./a.out
# first input is number of vertices
5
# second input is adjacent list of graph
# each node, number of the connections, adjacent node, weight of the edge, ...
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
# result, distance from node 0 to each node
0 0
1 2
2 2
3 1
4 3
```

Both programs take O(N2) as functional order.

But using priority queue makes it O((|V| + |E|)log|V|).
|V| is number of vertices and |E| is number of edges in graph.

single_source_shortest_path3.cpp uses Dijkstra's algorithm with priority queue and adjacent list.

```bash
$ g++ single_source_shortest_path3.cpp
$ ./a.out
# first input is number of vertices
5
# second input is adjacent list of graph
# each node, number of the connections, adjacent node, weight of the edge, ...
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
# result, distance from node 0 to each node
0 0
1 2
2 2
3 1
4 3
```

### Dijkstra's Algorithm

Dijksta's algorithm is generally used to find the shortest path from one vertex to another in graph.
When the pursuer visits each vertex, it records two things.

- the minimum distance from the start vertex
- whether the vertex is visited or not

The distance to the current vertex is calculated as sum of the weight of the edge and distance to the previous vertex.
After that, it visits an unvisited vertex from the current minimum path and do as same until it reaches the destination.

Using priority queue makes Dijkstra's algorithm more efficient.
Getting an item with the highest priority from the queue takes O(|V|) and this is repeated |V| times.
Furthermore, updating weight and visited or not takes O(|E|), this is taken against each edge, but the number of edges would be smaller than the number of the vertices. So it can be disregarded.
So total cost is O((|V| + |E|)|V|), almost equal to O(|V|2).

In case that the priority queue is implemented with minimum heap, getting an item takes O(log|V|).
So total performance cost is O((|V| + |E|)log|V|).

## Make Order

This program outputs a possible execution sequence of given projects.

The projects are reqresented as alphabet.
Pairs of two projects are also given as dependance relationship.

For example, (a, b) means that project a must be executed before project b.

```bash
$ g++ make_order1.cpp
$ ./a.out
# first input is number of projects
6
# second inputs are projects
a b c d e f
# third input is number of dependance relationships
5
# fourth inputs are dependance relationships
d a
b f
d b
a f
c d
# result is execution sequence
e f a b d c
```

make_order2.cpp uses depth first search.

```bash
$ g++ make_order2.cpp
$ ./a.out
# first input is number of projects
6
# second inputs are projects
a b c d e f
# third input is number of dependance relationships
5
# fourth inputs are dependance relationships
d a
b f
d b
a f
c d
# result is execution sequence
f e b a d c
```
