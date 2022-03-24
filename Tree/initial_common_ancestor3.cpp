#include <iostream>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int p, l, r;
};

Node T[N];

bool isDescendant(int rootIndex, int childIndex)
{
  if (rootIndex == NIL)
  {
    return false;
  }
  if (rootIndex == childIndex)
  {
    return true;
  }
  return isDescendant(T[rootIndex].l, childIndex) || isDescendant(T[rootIndex].r, childIndex);
}

int findAncestor(int rootIndex, int id1, int id2)
{
  if (rootIndex == NIL)
  {
    return NIL;
  }
  if (rootIndex == id1)
  {
    return id1;
  }
  if (rootIndex == id2)
  {
    return id2;
  }

  bool isLeft1 = isDescendant(T[rootIndex].l, id1);
  bool isLeft2 = isDescendant(T[rootIndex].l, id2);
  // node1 and node2 are on the other side of one another
  if (isLeft1 != isLeft2)
  {
    return rootIndex;
  }

  int ancestorIndex = isLeft1 ? T[rootIndex].l : T[rootIndex].r;
  return findAncestor(ancestorIndex, id1, id2);
}

int commonAncestor(int rootIndex, int id1, int id2)
{
  if (!isDescendant(rootIndex, id1) || !isDescendant(rootIndex, id2))
  {
    cout << "target nodes are not in tree" << endl;
    return NIL;
  }

  return findAncestor(rootIndex, id1, id2);
}

int main()
{
  int n, id, l, r;

  cin >> n;

  // initialization
  for (int i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> id >> l >> r;
    T[id].l = l;
    T[id].r = r;
    if (l != NIL)
    {
      T[l].p = id;
    }
    if (r != NIL)
    {
      T[r].p = id;
    }
  }

  // find root
  int rootIndex = 0;
  for (int i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      rootIndex = i;
      break;
    }
  }

  // indices of two nodes
  int p, q;

  cin >> p >> q;
  cout << commonAncestor(rootIndex, p, q) << endl;

  return 0;
}
