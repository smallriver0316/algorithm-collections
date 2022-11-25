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
  int countFirstZeroBits = firstOneBitIdx;
  if (countFirstOneBits + firstOneBitIdx == MAX_BIT_LEN || countFirstOneBits == 0)
  {
    return -1;
  }
  // change first zero bits into one bits => adding (2^countFirstZeroBits - 1)
  // -> lower bits are all 1s.
  // flip 1 bit by incresing digit => adding 1.
  // make lower (countFirstOneBits - 1) bits 1s => adding (2^(countFirstOneBits - 1) - 1).
  // result = x + (2 ^ countFirstZeroBits - 1) + 1 + (2 ^ (countFirstOneBits - 1) - 1)
  // = x + 2 ^ countFirstZeroBits + 2 ^ (countFirstOneBits - 1) - 1
  // = x + (1 << countFirstZeroBits) + (1 << (countFirstOneBits - 1)) - 1
  return x + (1 << countFirstZeroBits) + (1 << (countFirstOneBits - 1)) - 1;
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
  // flip the largest one bit in the first consecutive one bits into zero => subtracting (1 << (firstOneBitIdx + countFirstOneBits - 1))
  // change the largest zero bit in the first consecutive zero bits into one => adding (1 << (firstOneBitIdx- 1))
  return x - (1 << (firstOneBitIdx + countFirstOneBits - 1)) + (1 << (firstOneBitIdx - 1));
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
