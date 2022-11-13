#include <iostream>
#include <string>
using namespace std;

#define MAX_LEN 32

string convertBinary(double x)
{
  if (x == 1)
    return "1";
  if (x == 0)
    return "0";
  if (x > 1 || x < 0)
  {
    return "ERROR";
  }

  string bin = ".";
  while (x > 0)
  {
    if (bin.length() >= MAX_LEN)
    {
      return "ERROR";
    }

    double r = x * 2;
    if (r >= 1)
    {
      bin += "1";
      x = r - 1;
    }
    else
    {
      bin += "0";
      x = r;
    }
  }

  return bin;
}

int main()
{
  double x;
  cin >> x;
  string ret = convertBinary(x);
  cout << ret << endl;
  return 0;
}
