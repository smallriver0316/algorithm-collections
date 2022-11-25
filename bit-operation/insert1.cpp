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

int insertBits(int n, int m, int i, int j)
{
  int mask = 0;
  int len = shiftSize(n) + 1;
  for (int k = 0; k < len; k++)
  {
    if (k < i || k > j)
    {
      mask += (1 << k);
    }
  }

  return ((n & mask) | (m << i));
}

int main()
{
  int n, m, i, j;
  cin >> n >> m;
  cin >> i >> j;

  cout << "N: ";
  printBits(n);

  cout << "M: ";
  printBits(m);

  int len = shiftSize(m) + 1;
  if (len != (j - i + 1))
  {
    cout << "Bit Length is mismatched!" << endl;
    return -1;
  }

  int ret = insertBits(n, m, i, j);
  printBits(ret);

  return 0;
}
