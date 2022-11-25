#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> makePermutations(string s)
{
  vector<string> ret;

  if (s.length() == 1)
  {
    ret.push_back(s);
    return ret;
  }

  for (int i = 0; i < s.length(); i++)
  {
    string prev = s.substr(0, i);
    string curr = s.substr(i, 1);
    string next = s.substr(i + 1);
    string nokori = prev + next;
    vector<string> others = makePermutations(nokori);
    for (vector<string>::iterator it = others.begin(); it != others.end(); it++)
    {
      ret.push_back(curr + *it);
    }
  }
  return ret;
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
