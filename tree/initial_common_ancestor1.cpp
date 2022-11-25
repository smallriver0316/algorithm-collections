#include <iostream>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int p, l, r;
};

Node T[N];

int getDepth(int id)
{
  int depth = 0;
  int index = id;
  while (index != NIL)
  {
    depth++;
    index = T[index].p;
  }
  return depth;
}

int commonAncestor(int id1, int id2)
{
  int index1 = id1;
  int index2 = id2;
  int depth1 = getDepth(index1);
  int depth2 = getDepth(index2);

  // push back a node toward root until the two nodes have same depth
  int depthDiff = abs(depth1 - depth2);
  if (depth1 > depth2)
  {
    while (depthDiff > 0)
    {
      index1 = T[index1].p;
      depthDiff--;
    }
  }
  if (depth2 > depth1)
  {
    while (depthDiff > 0)
    {
      index2 = T[index2].p;
      depthDiff--;
    }
  }

  while (index1 != NIL && index2 != NIL && index1 != index2)
  {
    index1 = T[index1].p;
    index2 = T[index2].p;
  }

  return index1;
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
