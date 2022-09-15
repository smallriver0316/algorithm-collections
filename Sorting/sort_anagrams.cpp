#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> groupAnagrams(vector<string> array)
{
  unordered_map<string, vector<string>> map;
  for (vector<string>::iterator it = array.begin(); it != array.end(); it++)
  {
    string tmp = *it;
    sort(it->begin(), it->end());
    if (map.find(*it) == map.end())
    {
      map[*it] = {tmp};
    }
    else
    {
      map[*it].push_back(tmp);
    }
  }

  vector<string> ret;
  for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++)
  {
    ret.insert(ret.end(), it->second.begin(), it->second.end());
  }
  return ret;
}

int main()
{
  int n;
  vector<string> array;

  cin >> n;

  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    array.push_back(s);
  }

  vector<string> ret = groupAnagrams(array);
  for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
  {
    cout << *it << ", ";
  }
  cout << endl;

  return 0;
}
