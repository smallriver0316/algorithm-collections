#include <iostream>
using namespace std;

#define MAX_BIT_LEN 32

int findFirstOneBit(int x, int startIdx)
{
  int i = startIdx;
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

int findFirstZeroBit(int x, int startIdx)
{
  int i = startIdx;
  while ((x >> i) > 0)
  {
    if (((x >> i) & 1) == 0)
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
  int firstOneBitIdx = findFirstOneBit(x, 0);
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
  int firstZeroBitIdx = findFirstZeroBit(x, 0);
  int firstOneBitIdx = findFirstOneBit(x, firstZeroBitIdx + 1);
  int countFirstOneBits = countFirstOneBitSeq(x, firstOneBitIdx);
  if (countFirstOneBits + firstOneBitIdx == MAX_BIT_LEN || countFirstOneBits == 0)
  {
    return -1;
  }
  int countOneBits = countFirstOneBits + firstZeroBitIdx;
  int mask4clear = (~0) << (firstOneBitIdx + countFirstOneBits);
  int mask4flip = (~((~0) << countOneBits)) << (firstOneBitIdx + countFirstOneBits - countOneBits - 1);
  return (x & mask4clear) | mask4flip;
}

int main()
{
  int x, up, down;
  cin >> x;

  up = upsideNumber(x);
  cout << "Upside: " << up << endl;

  down = downsideNumber(x);
  if (down == -1)
  {
    cout << "Downside is None" << endl;
  }
  else
  {
    cout << "Downside: " << down << endl;
  }

  return 0;
}
