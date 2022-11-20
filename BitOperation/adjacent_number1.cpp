#include <iostream>
using namespace std;

#define MAX_BIT_LEN 32

int findFirstOneBit(int x)
{
  int i = 0;
  while ((x >> i) > 0)
  {
    if ((x >> i) & 1)
    {
      break;
    }
    i++;
  }
  return i;
}

int countFirstOneBitSeq(int x, int startIdx)
{
  int i = startIdx, count = 0;
  while ((x >> i) > 0)
  {
    if ((x >> i) & 1)
    {
      count++;
    }
    else
    {
      break;
    }
    i++;
  }
  return count;
}

int upsideNumber(int x)
{
  int firstOneBitIdx = findFirstOneBit(x);
  int countFirstOneBits = countFirstOneBitSeq(x, firstOneBitIdx);
  if (countFirstOneBits + firstOneBitIdx == MAX_BIT_LEN || countFirstOneBits == 0)
  {
    return -1;
  }
  int posFlip2One = firstOneBitIdx + countFirstOneBits;
  int remainedOneBits = countFirstOneBits - 1;
  int mask4clear = (~0) << (posFlip2One + 1);
  int mask4flip = (1 << posFlip2One) + ((1 << remainedOneBits) - 1);
  return (x & mask4clear) | mask4flip;
}

int downsideNumber(int x)
{
  int firstOneBitIdx = findFirstOneBit(x);
  int countFirstOneBits = countFirstOneBitSeq(x, firstOneBitIdx);
  if (countFirstOneBits + firstOneBitIdx == MAX_BIT_LEN || countFirstOneBits == 0)
  {
    return -1;
  }
  int mask4clear = (~0) << (firstOneBitIdx + countFirstOneBits);
  int mask4flip = ~((~0) << countFirstOneBits);
  return (x & mask4clear) | mask4flip;
}

int main()
{
  int x, up, down;
  cin >> x;

  up = upsideNumber(x);
  cout << "Upside: " << up << endl;

  down = downsideNumber(x);
  cout << "Downside: " << down << endl;

  return 0;
}
