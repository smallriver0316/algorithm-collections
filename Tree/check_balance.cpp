#include <iostream>
using namespace std;

#define N 100
#define NIL -1

/*
  key: key of node
  p: parent
  l: left child
  r: right child
*/
struct Node
{
  int key;
  int p, l, r;
};

Node T[N];

int checkBalance(int id)
{
  int h1 = 0, h2 = 0;
  if (T[id].l != NIL)
  {
    h1 = checkBalance(T[id].l) + 1;
  }
  if (T[id].r != NIL)
  {
    h2 = checkBalance(T[id].r) + 1;
  }
  if (h1 == NIL || h2 == NIL)
  {
    return NIL;
  }

  if (abs(h1 - h2) > 1)
  {
    return NIL;
  }
  else
  {
    return h1 > h2 ? h1 : h2;
  }
}

int main()
{
  int n, key, l, r;

  cin >> n;

  // initialization
  for (int i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // input tree
  for (int i = 0; i < n; i++)
  {
    cin >> key >> l >> r;
    T[i].key = key;
    T[i].l = l;
    T[i].r = r;
    if (l != NIL)
    {
      T[l].p = i;
    }
    if (r != NIL)
    {
      T[r].p = i;
    }
  }

  int rootIdx;
  for (int i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      rootIdx = i;
      break;
    }
  }

  int height = checkBalance(rootIdx);

  if (height != NIL)
  {
    cout << "Balanced Tree" << endl;
  }
  else
  {
    cout << "Unbalanced Tree" << endl;
  }

  return 0;
}
