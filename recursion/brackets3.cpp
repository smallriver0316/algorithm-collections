#include <iostream>
#include <set>
#include <string>
using namespace std;

string insertBracketInside(string str, int index)
{
  string left = str.substr(0, index + 1);
  string right = str.substr(index + 1);
  return left + "()" + right;
}

set<string> arrangeBrackets(int remained)
{
  set<string> st;
  if (remained == 0)
  {
    string s = "";
    st.insert(s);
  }
  else
  {
    set<string> prev = arrangeBrackets(remained - 1);
    for (set<string>::iterator it = prev.begin(); it != prev.end(); it++)
    {
      for (int i = 0; i < it->length(); i++)
      {
        if (it->at(i) == '(')
        {
          string s = insertBracketInside(*it, i);
          st.insert(s);
        }
      }
      st.insert("()" + *it);
    }
  }
  return st;
}

int main()
{
  int n;
  cin >> n;

  set<string> ret = arrangeBrackets(n);
  for (set<string>::iterator it = ret.begin(); it != ret.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}
