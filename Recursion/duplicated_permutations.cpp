#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> makePermutationsHelper(unordered_map<char, int> map, int len)
{
  vector<string> ret;

  if (len == 0)
  {
    ret.push_back("");
    return ret;
  }

  for (unordered_map<char, int>::iterator it = map.begin(); it != map.end(); it++)
  {
    if (it->second > 0)
    {
      it->second--;
      vector<string> others = makePermutationsHelper(map, len - 1);
      for (vector<string>::iterator jt = others.begin(); jt != others.end(); jt++)
      {
        ret.push_back(it->first + *jt);
      }
      it->second++;
    }
  }

  return ret;
}

vector<string> makePermutations(string s)
{
  int len = s.size();
  unordered_map<char, int> map;
  for (int i = 0; i < len; i++)
  {
    if (map.find(s.at(i)) == map.end())
    {
      map[s.at(i)] = 1;
    }
    else
    {
      map[s.at(i)]++;
    }
  }

  return makePermutationsHelper(map, len);
}

int main()
{
  string s;
  cin >> s;

  vector<string> ret = makePermutations(s);

  for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}
