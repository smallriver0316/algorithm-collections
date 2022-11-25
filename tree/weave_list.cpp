#include <iostream>
#include <vector>
using namespace std;

#define N 100

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

  int firstHead = first[0];
  first.erase(first.begin());
  prefix.push_back(firstHead);
  weaveList(first, second, prefix, results);
  prefix.pop_back();
  first.insert(first.begin(), firstHead);

  int secondHead = second[0];
  second.erase(second.begin());
  prefix.push_back(secondHead);
  weaveList(first, second, prefix, results);
  prefix.pop_back();
  second.insert(second.begin(), secondHead);
}

int main()
{
  try
  {
    vector<int> A, B;
    int n, m;
    int a, b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      A.push_back(a);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> b;
      B.push_back(b);
    }

    vector<int> prefix;
    vector<vector<int>> results;
    weaveList(A, B, prefix, results);

    for (int i = 0; i < results.size(); i++)
    {
      for (int j = 0; j < results[i].size(); j++)
      {
        cout << results[i][j] << " ";
      }
      cout << endl;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
