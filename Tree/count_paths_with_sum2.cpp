#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define N 10000
#define NIL -1

struct Node
{
  int key;
  int p, l, r;
};

Node T[N];

int findRoot(int n)
{
  for (int i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      return i;
    }
  }
  return NIL;
}

void printPath(vector<Node> nodes, int startIndex, int endIndex)
{
  for (int i = startIndex; i <= endIndex; i++)
  {
    cout << nodes[i].key << " ";
  }
  cout << endl;
}

void countPathWithSum(int index, int target, vector<Node> nodes, vector<int> sums)
{
  if (index != NIL)
  {
    int cur = sums.empty() ? T[index].key : sums.back() + T[index].key;
    nodes.push_back(T[index]);
    sums.push_back(cur);

    if (cur == target)
    {
      printPath(nodes, 0, nodes.size() - 1);
    }
    else
    {
      int diff = cur - target;
      for (int i = 0; i < sums.size(); i++)
      {
        if (sums[i] == diff)
        {
          printPath(nodes, i + 1, nodes.size() - 1);
        }
      }
    }

    countPathWithSum(T[index].l, target, nodes, sums);
    countPathWithSum(T[index].r, target, nodes, sums);
    nodes.pop_back();
  }
}

void countPathWithSumFromRoot(int sum, int n)
{
  int root = findRoot(n);
  vector<Node> nodes;
  vector<int> sums;

  countPathWithSum(root, sum, nodes, sums);
}

int main()
{
  int n, key, l, r;
  int target;

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

  cin >> target;

  countPathWithSumFromRoot(target, n);

  return 0;
}
