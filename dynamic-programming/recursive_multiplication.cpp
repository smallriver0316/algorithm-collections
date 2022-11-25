#include <iostream>
using namespace std;

int minProductHelper(int smaller, int bigger, int *memo)
{
  if (smaller == 0)
  {
    return 0;
  }
  else if (smaller == 1)
  {
    return bigger;
  }
  else if (memo[smaller] > 0)
  {
    return memo[smaller];
  }
  else
  {
    int s = smaller >> 1;
    int side1 = minProductHelper(s, bigger, memo);
    int side2 = side1;
    if (smaller % 2 == 1)
    {
      side2 = minProductHelper(smaller - s, bigger, memo);
    }

    memo[smaller] = side1 + side2;
    return memo[smaller];
  }
}

int minProduct(int x, int y)
{
  int bigger = x > y ? x : y;
  int smaller = x >= y ? y : x;
  int memo[smaller + 1];
  for (int i = 0; i < smaller + 1; i++)
  {
    memo[i] = 0;
  }
  return minProductHelper(smaller, bigger, memo);
}

int main()
{
  int x, y;

  cin >> x >> y;

  int ret = minProduct(x, y);
  cout << "result: " << ret << endl;

  return 0;
}
