#include <iostream>
#include <random>
#include <vector>
using namespace std;

#define MAX 32000
#define BITLEN_INT 5
#define BITSET_SIZE 1000

class BitSet
{
  unsigned int bitset[BITSET_SIZE + 1];

public:
  bool get(int pos)
  {
    // size of int is 4 byte x 8 bit = 32(=2^5) bit
    // x / 32 = x >> 5
    int wordNum = pos >> BITLEN_INT;
    // x mod 32 = x & (2^5 - 1)
    int bitNum = pos & 0x1F;
    return (bitset[wordNum] & (1 << bitNum)) != 0;
  }

  void set(int pos)
  {
    int wordNum = pos >> BITLEN_INT;
    int bitNum = pos & 0x1F;
    bitset[wordNum] |= 1 << bitNum;
  }
};

int main()
{
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand100(1, MAX);

  int n;
  vector<int> array;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    array.push_back(rand100(mt));
  }

  BitSet bitVector;
  for (vector<int>::iterator it = array.begin(); it != array.end(); it++)
  {
    if (bitVector.get(*it))
    {
      cout << *it << endl;
    }
    else
    {
      bitVector.set(*it);
    }
  }

  return 0;
}
