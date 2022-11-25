#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getSubsets(vector<int> &set, int index)
{
  vector<vector<int>> allsubsets;
  if (set.size() == index)
  {
    allsubsets.push_back({});
  }
  else
  {
    allsubsets = getSubsets(set, index + 1);
    int item = set[index];
    vector<vector<int>> moresubsets;
    for (vector<vector<int>>::iterator subset = allsubsets.begin(); subset != allsubsets.end(); subset++)
    {
      vector<int> newsubset;
      newsubset.insert(newsubset.end(), subset->begin(), subset->end());
      newsubset.push_back(item);
      moresubsets.push_back(newsubset);
    }
    allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());
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

  vector<vector<int>> results = getSubsets(totalset, 0);

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
