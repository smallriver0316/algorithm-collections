#include <iostream>
#include <vector>
using namespace std;

void arrangeBracketsHelper(int s, int st, int ed, int n, vector<int> &ret)
{
  int str = s;
  if (st == n && ed == n)
  {
    ret.push_back(str);
    return;
  }
  if (ed < st && ed < n)
  {
    ed++;
    arrangeBracketsHelper(str, st, ed, n, ret);
    ed--;
  }
  if (st < n)
  {
    int diff = 1 << (2 * n - st - ed - 1);
    str += diff;
    st++;
    arrangeBracketsHelper(str, st, ed, n, ret);
    str -= diff;
    st--;
  }
}

vector<int> arrangeBrackets(int n)
{
  /*
    st: number of ( usages
    ed: number of ) usages
  */
  int st = 1, ed = 0;
  /*
    handle bracket string as bit array.
    1 means (, and 0 is ).
  */
  int s = 1 << (2 * n - 1);
  vector<int> ret;
  arrangeBracketsHelper(s, st, ed, n, ret);
  return ret;
}

int main()
{
  int n;
  cin >> n;

  vector<int> ret = arrangeBrackets(n);

  for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
  {
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      if ((*it >> i) & 1)
      {
        cout << "(";
      }
      else
      {
        cout << ")";
      }
    }
    cout << endl;
  }

  return 0;
}
