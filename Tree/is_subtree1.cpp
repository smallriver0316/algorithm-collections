#include <iostream>
#include <vector>
#include <algorithm>
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

void preorderWalk(Node *T, int root, vector<int> &A)
{
  int left = T[root].l;
  int right = T[root].r;

  A.push_back(T[root].key);

  if (left != NIL)
  {
    preorderWalk(T, left, A);
  }
  if (right != NIL)
  {
    preorderWalk(T, right, A);
  }
}

bool isIncluded(vector<int> A1, vector<int> A2)
{
  for (int i = 0; i < A1.size(); i++)
  {
    if (A1[i] == A2[0])
    {
      bool included = true;
      for (int j = 0; j < A2.size(); j++)
      {
        if (A1[i + j] != A2[j])
        {
          included = false;
          break;
        }
      }
      if (included)
      {
        return true;
      }
    }
  }
  return false;
}

bool isSubTree(Node *T1, Node *T2, int n1, int n2)
{
  vector<int> A1, A2;
  int root1, root2;

  root1 = findRoot(T1, n1);
  root2 = findRoot(T2, n2);

  preorderWalk(T1, root1, A1);
  preorderWalk(T2, root2, A2);

  return isIncluded(A1, A2);
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
