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
    return calcStepNum(n - 1) + calcStepNum(n - 2) + calcStepNum(n - 3);
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
