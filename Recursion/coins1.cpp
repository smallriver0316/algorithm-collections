#include <iostream>
using namespace std;

// kinds of coins
#define SIZE 4

const int Coins[] = {25, 10, 5, 1};

void countPatternsHelper(int n, int coinIdx, int *result)
{
  if (n == 0)
  {
    (*result)++;
    return;
  }
  if (n < 0)
  {
    return;
  }
  for (int i = coinIdx; i < SIZE; i++)
  {
    countPatternsHelper(n - Coins[i], i, result);
  }
}

int countPatterns(int n)
{
  int result = 0;
  for (int i = 0; i < SIZE; i++)
  {
    if (n >= Coins[i])
    {
      countPatternsHelper(n - Coins[i], i, &result);
    }
  }
  return result;
}

int main()
{
  int n;
  cin >> n;

  int ret = countPatterns(n);

  cout << ret << endl;

  return 0;
}
