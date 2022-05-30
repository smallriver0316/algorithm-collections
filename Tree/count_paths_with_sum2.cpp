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

class SumIndex
{
  unordered_map<int, vector<int>> sums;

public:
  vector<int> get(int key)
  {
    if (sums.find(key) != sums.end())
    {
      return sums[key];
    }
    else
    {
      return {};
    }
  }

  void add(int key, int value)
  {
    if (sums.find(key) == sums.end())
    {
      sums[key] = {value};
    }
    else
    {
      sums[key].push_back(value);
    }
  }

  void remove(int key)
  {
    unordered_map<int, vector<int>>::iterator it = sums.find(key);
    if (it != sums.end())
    {
      sums[key].pop_back();
      if (sums[key].size() == 0)
      {
        sums.erase(it);
      }
    }
  }
};

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

void countPathWithSum(int index, int cur, int target, vector<Node> nodes, SumIndex sumIndex)
{
  if (index != NIL)
  {
    cur += T[index].key;
    nodes.push_back(T[index]);
    sumIndex.add(cur, nodes.size() - 1);

    if (cur == target)
    {
      printPath(nodes, 0, nodes.size() - 1);
    }
    else
    {
      int diff = cur - target;
      vector<int> indices = sumIndex.get(diff);
      for (int i = 0; i < indices.size(); i++)
      {
        printPath(nodes, indices[i] + 1, nodes.size() - 1);
      }
    }

    countPathWithSum(T[index].l, cur, target, nodes, sumIndex);
    countPathWithSum(T[index].r, cur, target, nodes, sumIndex);
    nodes.pop_back();
    sumIndex.remove(cur);
  }
}

void countPathWithSumFromRoot(int sum, int n)
{
  int root = findRoot(n);
  vector<Node> nodes;
  SumIndex sumIndex;

  countPathWithSum(root, 0, sum, nodes, sumIndex);
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
