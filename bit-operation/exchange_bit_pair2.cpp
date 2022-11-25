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
  // 0xaaaaaaaa = 10101010101010101010101010101010b
  // 0x55555555 = 01010101010101010101010101010101b
  return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
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
