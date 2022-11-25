#include <iostream>
using namespace std;

#define SIZE 4

const int Coins[] = {25, 10, 5, 1};

int countPatternsHelper(int remained, int coinIdx, int map[][SIZE])
{
  if (map[remained][coinIdx] > 0)
  {
    return map[remained][coinIdx];
  }
  if (coinIdx >= SIZE - 1)
  {
    return 1;
  }
  int coin = Coins[coinIdx];
  int patterns = 0;
  for (int i = 0; i * coin <= remained; i++)
  {
    patterns += countPatternsHelper(remained - i * coin, coinIdx + 1, map);
  }
  map[remained][coinIdx] = patterns;
  return patterns;
}

int countPatterns(int n)
{
  int map[n + 1][SIZE];
  // initialize
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      map[i][j] = 0;
    }
  }
  return countPatternsHelper(n, 0, map);
}

int main()
{
  int n;
  cin >> n;

  int ret = countPatterns(n);
  cout << ret << endl;

  return 0;
}
