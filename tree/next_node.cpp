#include <iostream>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int p, l, r;
};

Node T[N];

int leftMostChild(int id)
{
  if (id == NIL)
  {
    return NIL;
  }

  int left = id;
  while (T[left].l != NIL)
  {
    left = T[left].l;
  }
  return left;
}

int nextNode(int id)
{
  if (id == NIL)
  {
    return NIL;
  }

  if (T[id].r != NIL)
  {
    return leftMostChild(T[id].r);
  }
  else
  {
    int x = id;
    int parent = T[id].p;
    while (parent != NIL && x != NIL && T[parent].l != x)
    {
      x = parent;
      parent = T[parent].p;
    }
    return parent;
  }
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

  int q;

  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> id;
    cout << nextNode(id) << endl;
  }

  return 0;
}
