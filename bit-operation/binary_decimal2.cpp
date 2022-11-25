#include <iostream>
#include <string>
using namespace std;

#define MAX_LEN 32

string convertBinary(double num)
{
  if (num == 1)
    return "1";
  if (num == 0)
    return "0";
  if (num > 1 || num < 0)
    return "ERROR";

  string bin = ".";
  double frac = 0.5;
  while (num > 0)
  {
    if (bin.length() > MAX_LEN)
    {
      return "ERROR";
    }
    if (num >= frac)
    {
      bin += "1";
      num -= frac;
    }
    else
    {
      bin += "0";
    }
    frac /= 2;
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
