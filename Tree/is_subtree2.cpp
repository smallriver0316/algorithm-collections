#include <iostream>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int key;
  int p, l, r;
};

int findRoot(Node *T, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      break;
    }
  }
  return i;
}

bool matchTree(Node *T1, Node *T2, int index1, int index2)
{
  int left1 = T1[index1].l;
  int right1 = T1[index1].r;

  if (index1 == NIL && index2 != NIL)
  {
    return false;
  }
  else if (index2 == NIL)
  {
    return true;
  }
  else if (T1[index1].key == T2[index2].key)
  {
    int left2 = T2[index2].l;
    int right2 = T2[index2].r;
    return matchTree(T1, T2, left1, left2) && matchTree(T1, T2, right1, right2);
  }
  else
  {
    return matchTree(T1, T2, left1, index2) || matchTree(T1, T2, right1, index2);
  }
}

bool isSubTree(Node *T1, Node *T2, int n1, int n2)
{
  int root1, root2;

  root1 = findRoot(T1, n1);
  root2 = findRoot(T2, n2);

  return matchTree(T1, T2, root1, root2);
}

int main()
{
  Node T1[N], T2[N];
  int n1, n2, key, l, r;

  // T1
  cin >> n1;

  // initialization
  for (int i = 0; i < n1; i++)
  {
    T1[i].p = T1[i].l = T1[i].r = NIL;
  }

  // input
  for (int i = 0; i < n1; i++)
  {
    cin >> key >> l >> r;
    T1[i].key = key;
    T1[i].l = l;
    T1[i].r = r;
    if (l != NIL)
    {
      T1[l].p = i;
    }
    if (r != NIL)
    {
      T1[r].p = i;
    }
  }

  // T2
  cin >> n2;

  // initialization
  for (int i = 0; i < n2; i++)
  {
    T2[i].p = T2[i].l = T2[i].r = NIL;
  }

  // input
  for (int i = 0; i < n2; i++)
  {
    cin >> key >> l >> r;
    T2[i].key = key;
    T2[i].l = l;
    T2[i].r = r;
    if (l != NIL)
    {
      T2[l].p = i;
    }
    if (r != NIL)
    {
      T2[r].p = i;
    }
  }

  if (isSubTree(T1, T2, n1, n2))
  {
    cout << "Subtree" << endl;
  }
  else
  {
    cout << "Not Subtree" << endl;
  }

  return 0;
}
