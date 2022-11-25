#include <iostream>
#include <vector>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int key;
  int p, l, r;
};

Node T[N];

vector<int> cloneList(vector<int> v)
{
  vector<int> clone;
  for (int i = 0; i < v.size(); i++)
  {
    clone.push_back(v[i]);
  }
  return clone;
}

void weaveList(vector<int> first, vector<int> second, vector<int> prefix, vector<vector<int>> &results)
{
  if (first.empty() || second.empty())
  {
    vector<int> result = cloneList(prefix);
    result.insert(result.end(), first.begin(), first.end());
    result.insert(result.end(), second.begin(), second.end());
    results.push_back(result);
    return;
  }

  // pop front
  int firstHead = first[0];
  first.erase(first.begin());
  // add front to prefix
  prefix.push_back(firstHead);
  weaveList(first, second, prefix, results);
  // revert
  prefix.pop_back();
  first.insert(first.begin(), firstHead);

  // pop front
  int secondHead = second[0];
  second.erase(second.begin());
  // add front ti prefix
  prefix.push_back(secondHead);
  weaveList(first, second, prefix, results);
  // revert
  prefix.pop_back();
  second.insert(second.begin(), secondHead);
}

vector<vector<int>> bst2array(int rootIndex)
{
  vector<vector<int>> results;
  if (rootIndex == NIL)
  {
    vector<int> result;
    results.push_back(result);
    return results;
  }

  vector<int> prefix;
  // bst2array() does only pushing back root node, because root must be the first item in array.
  // Other nodes will be pushed by weaveList().
  prefix.push_back(T[rootIndex].key);

  vector<vector<int>> leftVector = bst2array(T[rootIndex].l);
  vector<vector<int>> rightVector = bst2array(T[rootIndex].r);

  // weaveList() can calculate all possible merged arrays of left and right vectors.
  // So here what can be do is only to create the possible combination of left and right.
  for (int i = 0; i < leftVector.size(); i++)
  {
    for (int j = 0; j < rightVector.size(); j++)
    {
      vector<vector<int>> weaved;
      weaveList(leftVector[i], rightVector[j], prefix, weaved);
      results.insert(results.end(), weaved.begin(), weaved.end());
    }
  }

  return results;
}

int main()
{
  int n, key, l, r, root;

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

  // find root
  for (int i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      root = i;
      break;
    }
  }

  vector<vector<int>> results = bst2array(root);

  for (int i = 0; i < results.size(); i++)
  {
    for (int j = 0; j < results[i].size(); j++)
    {
      cout << results[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
