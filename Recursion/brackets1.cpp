#include <iostream>
#include <vector>
#include <string>
using namespace std;

void arrangeBracketsHelper(string s, int st, int ed, int n, vector<string> &ret)
{
  string str = s;
  if (st == n && ed == n)
  {
    ret.push_back(str);
    return;
  }
  if (ed < st && ed < n)
  {
    str += ")";
    ed++;
    arrangeBracketsHelper(str, st, ed, n, ret);
    str = s;
    ed--;
  }
  if (st < n)
  {
    str += "(";
    st++;
    arrangeBracketsHelper(str, st, ed, n, ret);
    str = s;
    st--;
  }
}

vector<string> arrangeBrackets(int n)
{
  /*
    st: number of ( usages
    ed: number of ) usages
  */
  int st = 1, ed = 0;
  string s = "(";
  vector<string> ret;
  arrangeBracketsHelper(s, st, ed, n, ret);
  return ret;
}

int main()
{
  int n;
  cin >> n;

  vector<string> ret = arrangeBrackets(n);
  for (vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
  {
    cout << *it << endl;
  }

  return 0;
}