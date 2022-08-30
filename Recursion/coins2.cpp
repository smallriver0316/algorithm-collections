#include <iostream>
using namespace std;

#define SIZE 4

const int Coins[] = {25, 10, 5, 1};

int countPatterns(int remained, int coinIdx)
{
  if (coinIdx >= SIZE - 1)
  {
    return 1;
  }

  int coin = Coins[coinIdx];
  int patterns = 0;
  for (int i = 0; i * coin <= remained; i++)
  {
    patterns += countPatterns(remained - i * coin, coinIdx + 1);
  }
  return patterns;
}

int main()
{
  int n;
  cin >> n;

  int ret = countPatterns(n, 0);
  cout << ret << endl;

  return 0;
}
