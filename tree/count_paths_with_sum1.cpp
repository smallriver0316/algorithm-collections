#include <iostream>
#include <vector>
using namespace std;

#define N 10000
#define NIL -1

struct Node
{
  int key;
  int p, l, r;
};

Node T[N];

void countPathWithSum(int index, int cur, int sum, vector<Node> arr)
{
  if (index != NIL)
  {
    cur += T[index].key;
    arr.push_back(T[index]);
    if (cur == sum)
    {
      for (vector<Node>::iterator it = arr.begin(); it != arr.end(); it++)
      {
        cout << it->key << " ";
      }
      cout << endl;
    }
    countPathWithSum(T[index].l, cur, sum, arr);
    countPathWithSum(T[index].r, cur, sum, arr);
  }
}

void countPathWithSumFromNode(int sum, int n)
{
  int cur = 0;
  vector<Node> arr;
  for (int i = 0; i < n; i++)
  {
    countPathWithSum(i, 0, sum, arr);
  }
}

int main()
{
  int n, key, l, r;
  int sum;

  cin >> n;

  // initialization
  for (int i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // input
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

  cin >> sum;

  countPathWithSumFromNode(sum, n);

  return 0;
}
