# Tree

## Rooted Tree

It is implementation of rooted tree.

Inputs are node ID, number of children nodes(degree of node) and IDs of the children.
The nodes of children in the inputs are supporsed to be arranged in an order from left to right.

Outputs are information of each node as below.

```bash
$ g++ rooted_tree.cpp
$ ./a.out
# initial input is number of nodes
13
# each node information
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0
# result
node 0: parent = -1, depth = 0, root, [1, 4, 10]
node 1: parent = 0, depth = 1, internal node, [2, 3]
node 2: parent = 1, depth = 2, leaf, []
node 3: parent = 1, depth = 2, leaf, []
node 4: parent = 0, depth = 1, internal node, [5, 6, 7]
node 5: parent = 4, depth = 2, leaf, []
node 6: parent = 4, depth = 2, leaf, []
node 7: parent = 4, depth = 2, internal node, [8, 9]
node 8: parent = 7, depth = 3, leaf, []
node 9: parent = 7, depth = 3, leaf, []
node 10: parent = 0, depth = 1, internal node, [11, 12]
node 11: parent = 10, depth = 2, leaf, []
node 12: parent = 10, depth = 2, leaf, []
```

## Binary Tree

It is implementation of binary tree.

Inputs are node ID, left child and right child.

Outputs are information of each nodes as below.

```bash
$ g++ binary_tree.cpp
$ ./a.out
# initial input is number of nodes
9
# each node information; ID, left child, right child
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
# result
node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
node 1: parent = 0, sibling = 1, degree = 2, depth = 1, height = 1, internal node
node 2: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
node 3: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
node 4: parent = 0, sibling = 4, degree = 2, depth = 1, height = 2, internal node
node 5: parent = 4, sibling = 5, degree = 2, depth = 2, height = 1, internal node
node 6: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
node 7: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
node 8: parent = 4, sibling = 8, degree = 0, depth = 2, height = 0, leaf
```

## Tree Walk

It is implementation of tree walk, output 3 patterns of walking binary-tree.

1. Preorder Tree Walk

   Walk as root->left->right

2. Inorder Tree Walk

   Walk as left->root->right

3. Postorder Tree Walk

   Walk as left->right->root

```bash
$ g++ tree_walk.cpp
$ ./a.out
# initial input is number of nodes
9
# each node information; ID, left child, right child
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
# result
Preorder
0 1 2 3 4 5 6 7 8
Inorder
2 1 3 0 6 5 7 4 8
Postorder
2 3 1 6 7 5 8 4 0
```

### Search in Tree

When searching a node in tree, it would be useful to use recurcive processing.
Other than binary search tree(BST), it is difficult to figure out where a target node is in left or right siblings or children of them. So it is required to do the recursive processing against each partial tree agaist left or right siblings. This enables the search with short codes and high performance.

## Reconstruction of Tree

It reconstructs binary tree.

Given Preorder and Inorder node array, this program output Postorder array.

```bash
$ g++ reconstruct_tree.cpp
$ ./a.out
# initial input is number of nodes
5
# Preorder node array
1 2 3 4 5
# Inorder node array
3 2 4 1 5
# result is Postorder
3 4 2 5 1
```

## Minimal Binary Search Tree

It creates binary search tree of minimal depth,
when nodes of ascending order are given as input.

```bash
$ g++ minimal_binary_search_tree.cpp
$ ./a.out
# first input is number of nodes
6
# second inputs are nodes that must be in ascending order.
1 2 3 4 5 6
# result
index 0: key = 1, parent = 1, sibling = 0, degree = 0, leaf
index 1: key = 2, parent = 3, sibling = 1, degree = 2, internal node
index 2: key = 3, parent = 1, sibling = 2, degree = 0, leaf
index 3: key = 4, parent = -1, sibling = -1, degree = 2, root
index 4: key = 5, parent = 5, sibling = 4, degree = 0, leaf
index 5: key = 6, parent = 3, sibling = 5, degree = 1, internal node
```

## Depth Linked List

It creates linked lists from a given binary search tree.
Each linked list must be composed of the nodes of the same depth.

```bash
$ g++ depth_linked_list.cpp
$ ./a.out
# first input is number of node
7
# second inputs are each node information, key, left child index, right child index
0 -1 -1
1 0 2
2 -1 -1
3 1 5
4 -1 -1
5 4 6
6 -1 -1
# result, linked list of each depth
depth0: 3
depth1: 1 5
depth2: 0 2 4 6
```

## Check Balanced Binary Tree

It checks whether a given tree is balanced binary tree or not.
Balanced binary tree is defined as a tree that heights of partial trees against every node is same or different only by one.

```bash
$ g++ check_balance.cpp
$ ./a.out
# first input is number of node
6
# second inputs are each node information, key, left child index, right child index
0 -1 -1
1 0 -1
2 -1 -1
3 1 2
4 3 5
5 -1 -1
# result, balanced binary tree or not
Unbalanced Tree
```

This algorithm calculates the height of tree with recursive processing.
It takes performance cost of O(N) and spatial cost of O(H).
N is number of nodes, H is height of tree.

## Check Binary Search Tree

It checks whether a given tree is binary search tree or not.
Binary search tree is defined as a tree in which the left children are no more than the parent node and the right children are more than the parent node.

```bash
$ g++ check_binary_search_tree1.cpp
$ ./.out
# first input is number of node
8
# second inputs are each node information, key, left child index, right child index
3 -1 -1
5 0 2
7 -1 -1
10 1 4
15 -1 5
17 -1 -1
20 3 7
30 -1 -1
# result
BST
```

check_binary_search_tree2.cpp is almost same.

```bash
$ g++ check_binary_search_tree2.cpp
$ ./.out
# first input is number of node
4
# second inputs are each node information, key, left child index, right child index
25 -1 -1
10 -1 0
20 1 3
30 -1 -1
# result
Not BST
```

These algorithms check all nodes, so the performance cost is O(N).

## Next Node in Binary Search Tree

It outputs the next node of a given node in binary search tree.

This next node is the next node in inorder tree walk.

```bash
$ next_node.cpp
$ ./a.out
# first input is number of tree nodes
9
# second input is tree information, node index, left child index, right child index
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
# third input is number of questions
3
# fourth input is target node index
1
# result is the next node
3
# target node
3
# next node
0
# target node
4
# next node
8
```

## Initial Common Ancestor

This program outputs the initial common ancestor of given two nodes in binary tree.

This tree doesn't always have to be binary search tree, so the order of nodes is not fixed.

Index of each node is supposed to be sequential integer from 0 for convenience.

initial_common_ancestor1.cpp uses depth of each target.

```bash
$ g++ initial_common_ancestor1.cpp
$ ./a.out
# first input is number of tree nodes
8
# second input is node information; node index, left child index, right child index
0 -1 -1
1 0 2
2 -1 -1
3 1 4
4 -1 5
5 -1 -1
6 3 7
7 -1 -1
# third inputs are two target nodes
2 4
# result is initial common ancestor of the targets
3
```

initial_common_ancestor2.cpp uses link to parent node of each target.

```bash
$ g++ initial_common_ancestor2.cpp
$ ./a.out
# first input is number of tree nodes
8
# second input is node information; node index, left child index, right child index
0 -1 -1
1 0 2
2 -1 -1
3 1 4
4 -1 5
5 -1 -1
6 3 7
7 -1 -1
# third inputs are two target nodes
2 5
# result is initial common ancestor of the targets
3
```

initial_common_ancestor3.cpp searches the ancestor from the root of tree.

```bash
$ g++ initial_common_ancestor2.cpp
$ ./a.out
# first input is number of tree nodes
8
# second input is node information; node index, left child index, right child index
0 -1 -1
1 0 2
2 -1 -1
3 1 4
4 -1 5
5 -1 -1
6 3 7
7 -1 -1
# third inputs are two target nodes
0 3
# result is initial common ancestor of the targets
3
```

## Array from BST

This program outputs all arrays which can create a given Binary Search Tree.

When creating a BST, the root node must be given at first.
But the child nodes; left and right nodes can given in any order.
So the possible arrays are (root, left, right) or (root, right, left).
This rule is applied to all partial trees of the BST.

```bash
$ g++ bst2array.cpp
$ ./a.out
# first input is number of nodes
10
# second input is node information; node key value, left child index, right child index
5 -1 -1
10 0 2
15 -1 -1
20 1 4
25 -1 -1
50 3 6
60 -1 8
65 -1 -1
70 7 9
80 -1 -1
# result
50 20 10 5 15 25 60 70 65 80
50 20 10 5 15 60 25 70 65 80
50 20 10 5 15 60 70 25 65 80
50 20 10 5 15 60 70 65 25 80
50 20 10 5 15 60 70 65 80 25
50 20 10 5 60 15 25 70 65 80
50 20 10 5 60 15 70 25 65 80
50 20 10 5 60 15 70 65 25 80
50 20 10 5 60 15 70 65 80 25
50 20 10 5 60 70 15 25 65 80
50 20 10 5 60 70 15 65 25 80
...
```

In order to implement this algorithm, it is necessary to "weave" two arrays.
"weave" means calculating combination of how to merge the arrays without changing the order of items in each array.

This sample program is weaveList.cpp.

```bash
$ g++ weaveList.cpp
$ ./a.out
# first input is number of items in the first array.
3
# second input is the first array.
1 2 3
# third input is number of items in the second array.
3
# fourth input is the second array.
4 5 6
# result
1 2 3 4 5 6
1 2 4 3 5 6
1 2 4 5 3 6
1 2 4 5 6 3
1 4 2 3 5 6
1 4 2 5 3 6
1 4 2 5 6 3
1 4 5 2 3 6
1 4 5 2 6 3
1 4 5 6 2 3
4 1 2 3 5 6
4 1 2 5 3 6
4 1 2 5 6 3
4 1 5 2 3 6
4 1 5 2 6 3
4 1 5 6 2 3
4 5 1 2 3 6
4 5 1 2 6 3
4 5 1 6 2 3
4 5 6 1 2 3
```

## Subtree Matching

This program determins whether one tree is subtree of another.

This program requires two tree as arguments, T1 and T2.
T1 is larger than T2, and T2 can be subtree of T1.

is_subtree1.cpp uses pre-order walk to convert tree to array.
After that, compare two arrays.
This takes O(N + M + NM) as performance cost.
N and M are number of T1 and T2.

```bash
$ g++ is_subtree1.cpp
$ ./a.out
# first input is number of nodes in T1
10
# second input is node information; node key value, left child index, right child index in T1
5 -1 -1
10 0 2
15 -1 -1
20 1 4
25 -1 -1
50 3 6
60 -1 8
65 -1 -1
70 7 9
80 -1 -1
# third input is number of nodes in T2
5
# fourth input is node key value, left child index, right child index in T2
5 -1 -1
10 0 2
15 -1 -1
20 1 4
25 -1 -1
# result; Subtree or Not Subtree
Subtree
```

is_subtree2.cpp is improved one.
It matches trees with recursion.
It takes O(log N + log M) as performance cost.

```bash
$ g++ is_subtree2.cpp
$ ./a.out
# first input is number of nodes in T1
10
# second input is node information; node key value, left child index, right child index in T1
5 -1 -1
10 0 2
15 -1 -1
20 1 4
25 -1 -1
50 3 6
60 -1 8
65 -1 -1
70 7 9
80 -1 -1
# third input is number of nodes in T2
5
# fourth input is node key value, left child index, right child index in T2
5 -1 -1
10 0 2
15 -1 -1
20 1 4
25 -1 -1
# result; Subtree or Not Subtree
Subtree
```
