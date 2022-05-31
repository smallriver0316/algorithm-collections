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

int commonAncestor(int id1, int id2)
{
  int index1 = id1;
  int index2 = id2;
  if (isDescendant(index1, index2))
  {
    return index1;
  }
  if (isDescendant(index2, index1))
  {
    return index2;
  }

  index1 = T[index1].p;
  while (index1 != NIL)
  {
    if (isDescendant(index1, index2))
    {
      return index1;
    }
    index1 = T[index1].p;
  }
  return NIL;
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

  // indices of two nodes
  int p, q;

  cin >> p >> q;
  cout << commonAncestor(p, q) << endl;

  return 0;
}
