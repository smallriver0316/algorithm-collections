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
