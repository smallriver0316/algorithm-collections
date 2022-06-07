#include <iostream>
using namespace std;

int calcStepNum(int n)
{
  if (n == 1)
  {
    return 1;
  }
  if (n == 2)
  {
    return 1 + calcStepNum(1);
  }
  if (n == 3)
  {
    return 1 + calcStepNum(2) + calcStepNum(1);
  }
  if (n >= 4)
  {
    int a = calcStepNum(1);
    int b = calcStepNum(2);
    int c = calcStepNum(3);
    int d;
    for (int i = 4; i <= n; i++)
    {
      d = a + b + c;
      a = b;
      b = c;
      c = d;
    }
    return d;
  }
  return 0;
}

int main()
{
  int n;

  cin >> n;

  int ret = calcStepNum(n);
  cout << ret << endl;

  return 0;
}
