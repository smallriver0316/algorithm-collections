#include <iostream>
#include <math.h>
using namespace std;

#define MAX 100000
#define NIL -1

/*
  key: key
  p: parent node
  l: left child
  r: right child
*/
struct Node
{
  int key, p, l, r;
};

Node T[MAX];

int createMinimalBST(int startIndex, int endIndex)
{
  int num = endIndex - startIndex + 1;
  if (num == 1)
  {
    return startIndex;
  }

  int depth = 0;
  while (num > pow(2, depth + 1) - 1)
  {
    depth++;
  }

  int numOfLastLayer = num - (pow(2, depth) - 1);
  int lastLayerLeft = 0;
  if (numOfLastLayer - pow(2, depth - 1) > 0)
  {
    lastLayerLeft = pow(2, depth - 1);
  }
  else
  {
    lastLayerLeft = numOfLastLayer;
  }
  int rootIndex = startIndex + lastLayerLeft + (pow(2, depth) - 1) / 2;
  int leftIndex = NIL;
  int rightIndex = NIL;
  if (startIndex <= rootIndex - 1)
  {
    leftIndex = createMinimalBST(startIndex, rootIndex - 1);
  }
  if (rootIndex + 1 <= endIndex)
  {
    rightIndex = createMinimalBST(rootIndex + 1, endIndex);
  }
  T[rootIndex].l = leftIndex;
  T[rootIndex].r = rightIndex;
  T[leftIndex].p = rootIndex;
  T[rightIndex].p = rootIndex;
  return rootIndex;
}

int getSibling(int index)
{
  if (T[index].p == NIL)
    return NIL;
  if (T[T[index].p].r != index && T[T[index].p].l != NIL)
  {
    return T[T[index].p].l;
  }
  if (T[T[index].p].l != index && T[T[index].p].r != NIL)
  {
    return T[T[index].p].r;
  }
  return NIL;
}

void printNode(int index)
{
  cout << "index " << index << ": ";
  cout << "key = " << T[index].key << ", ";
  cout << "parent = " << T[index].p << ", ";
  cout << "sibling = " << getSibling(index) << ", ";
  int degree = 0;
  if (T[index].l != NIL && T[index].r != NIL)
  {
    degree = 2;
  }
  else if (T[index].l != NIL || T[index].r != NIL)
  {
    degree = 1;
  }
  cout << "degree = " << degree << ", ";
  if (T[index].p == NIL)
  {
    cout << "root" << endl;
  }
  else if (T[index].l != NIL || T[index].r != NIL)
  {
    cout << "internal node" << endl;
  }
  else
  {
    cout << "leaf" << endl;
  }
}

int main()
{
  int n, key, depth;
  Node *root = nullptr;

  cin >> n;

  // initialization and iput
  for (int i = 0; i < n; i++)
  {
    cin >> key;
    T[i].p = T[i].l = T[i].r = NIL;
    T[i].key = key;
  }

  createMinimalBST(0, n - 1);

  // output
  for (int i = 0; i < n; i++)
  {
    printNode(i);
  }

  return 0;
}
