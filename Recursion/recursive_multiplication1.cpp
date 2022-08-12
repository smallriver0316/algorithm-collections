#include <iostream>
#include <vector>
using namespace std;

vector<int> calcExps(int x, int exp, vector<int> exps)
{
  int shifted = 1 << exp;
  int nextX = x;
  int nextExp = exp - 1;

  int candidate = x - shifted;
  if (candidate >= 0)
  {
    nextX = candidate;
    exps.push_back(exp);
  }

  if (nextExp >= 0)
  {
    return calcExps(nextX, nextExp, exps);
  }
  else
  {
    return exps;
  }
}

int calcProduct(int x, int y)
{
  if (x == 0 || y == 0)
  {
    return 0;
  }

  int smaller = x >= y ? y : x;
  int bigger = x > y ? x : y;

  // maximum exponent
  int maxExp = 0;
  int shifted = 1 << maxExp;
  while (smaller >= shifted)
  {
    shifted = 1 << ++maxExp;
  }
  maxExp -= 1;

  vector<int> exps;
  exps = calcExps(smaller, maxExp, exps);

  int ret = 0;
  for (vector<int>::iterator it = exps.begin(); it != exps.end(); it++)
  {
    ret += (bigger << *it);
  }

  return ret;
}

int main()
{
  int x, y;

  cin >> x >> y;

  int ret = calcProduct(x, y);
  cout << "result: " << ret << endl;

  return 0;
}
