#include <iostream>
#include <vector>
using namespace std;

vector<int> convertInt2Set(int x, vector<int> &set)
{
  vector<int> subset;
  int index = 0;
  for (int i = x; i > 0; i >>= 1)
  {
    if ((i & 1) == 1)
    {
      subset.push_back(set[index]);
    }
    index++;
  }
  return subset;
}

vector<vector<int>> getSubsets(vector<int> &set)
{
  vector<vector<int>> allsubsets;
  int max = 1 << set.size();
  for (int i = 0; i < max; i++)
  {
    vector<int> subset = convertInt2Set(i, set);
    allsubsets.push_back(subset);
  }

  return allsubsets;
}

int main()
{
  int n, elem;
  vector<int> totalset;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> elem;
    totalset.push_back(elem);
  }

  vector<vector<int>> results = getSubsets(totalset);
  for (vector<vector<int>>::iterator it = results.begin(); it != results.end(); it++)
  {
    cout << "{ ";
    for (vector<int>::iterator jt = it->begin(); jt != it->end(); jt++)
    {
      cout << *jt << ", ";
    }
    cout << "}" << endl;
  }

  return 0;
}
