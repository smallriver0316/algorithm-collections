#include <iostream>
using namespace std;

#define MAX_LEN 32

int shiftSize(int x)
{
  int size = 0;
  for (int i = 0; i < MAX_LEN; i++)
  {
    if (x <= (1 << i))
    {
      if (x >> i)
      {
        size = i;
      }
      else
      {
        size = i - 1;
      }
      break;
    }
  }
  return size;
}

void printBits(int x)
{
  int bitlen = shiftSize(x);

  for (int i = bitlen; i >= 0; i--)
  {
    int mask = (1 << i);
    if ((x & mask) >> i)
    {
      cout << 1;
    }
    else
    {
      cout << 0;
    }
  }
  cout << endl;
}

int exchangePairs(int x)
{
  // mask of lower 2 bits
  int mask = ~((~0) << 2);
  int ret = 0;
  for (int i = 0; (x >> i) > 0; i += 2)
  {
    int pair = (x >> i) & mask;
    switch (pair)
    {
    case 2: // 10 -> 01
      ret = (1 << i) | ret;
      break;
    case 1: // 01 -> 10
      ret = (2 << i) | ret;
      break;
    default:
      // 11 -> 11, 00 -> 00
      ret = (pair << i) | ret;
      break;
    }
  }
  return ret;
}

int main()
{
  int x;
  cin >> x;

  cout << "input: ";
  printBits(x);

  int ret = exchangePairs(x);
  cout << ret << endl;
  cout << "output: ";
  printBits(ret);

  return 0;
}
