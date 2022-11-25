#include <iostream>
using namespace std;

int countBitDiff1(int a, int b)
{
  int i = 0, count = 0;
  while ((a >> i) > 0 || (b >> i) > 0)
  {
    if (((a >> i) & 1) != ((b >> i) & 1))
    {
      count++;
    }
    i++;
  }
  return count;
}

int countBitDiff2(int a, int b)
{
  int x = a ^ b;
  int i = 0, count = 0;
  while ((x >> i) > 0)
  {
    if ((x >> i) & 1)
    {
      count++;
    }
    i++;
  }
  return count;
}

int countBitDiff3(int a, int b)
{
  int count = 0;
  for (int x = a ^ b; x != 0; x >>= 1)
  {
    count += (x & 1);
  }
  return count;
}

int countBitDiff4(int a, int b)
{
  int count = 0;
  // here invert lower one bit to zero with x & (x - 1)
  // this function count the number of 1 bit by counting times of the flip.
  for (int x = a ^ b; x != 0; x = x & (x - 1))
  {
    count++;
  }
  return count;
}

int main()
{
  int a, b;
  cin >> a >> b;
  int ret1 = countBitDiff1(a, b);
  cout << ret1 << endl;
  int ret2 = countBitDiff2(a, b);
  cout << ret2 << endl;
  int ret3 = countBitDiff3(a, b);
  cout << ret3 << endl;
  int ret4 = countBitDiff4(a, b);
  cout << ret4 << endl;
  return 0;
}
