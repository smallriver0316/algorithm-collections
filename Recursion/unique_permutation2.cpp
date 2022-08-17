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

  string first = s.substr(0, 1);
  string nokori = s.substr(1);
  vector<string> others = makePermutations(nokori);
  for (vector<string>::iterator it = others.begin(); it != others.end(); it++)
  {
    string other = *it;
    for (int i = 0; i <= other.length(); i++)
    {
      string perm = other;
      perm.insert(i, first);
      ret.push_back(perm);
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
