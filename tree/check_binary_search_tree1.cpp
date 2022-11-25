#include <iostream>
using namespace std;

#define N 100
#define NIL -1

struct Node
{
  int key;
  int p, l, r;
};

Node T[N];

int findRoot(int n)
{
  int i = 0;
  for (i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      break;
    }
  }
  return i;
}

// walk as inorder
bool checkBST(int index, int min, int max)
{
  if ((min != NIL && T[index].key < min) || (max != NIL && T[index].key >= max))
  {
    return false;
  }

  int left = T[index].l;
  int right = T[index].r;

  if (left != NIL)
  {
    if (!checkBST(left, min, T[index].key))
    {
      return false;
    }
  }
  if (right != NIL)
  {
    if (!checkBST(right, T[index].key, max))
    {
      return false;
    }
  }
  return true;
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

  int rootIdx = findRoot(n);

  if (checkBST(rootIdx, NIL, NIL))
  {
    cout << "BST" << endl;
  }
  else
  {
    cout << "Not BST" << endl;
  }

  return 0;
}
