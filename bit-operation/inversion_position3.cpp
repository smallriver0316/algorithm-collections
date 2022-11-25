#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_LEN 32

int longestSequence(int x)
{
  if (~x == 0)
    return MAX_LEN;

  int currLen = 0, prevLen = 0, maxLen = 1;
  while (x != 0)
  {
    if ((x & 1) == 1)
    {
      // current bit is 1
      currLen++;
    }
    else
    {
      // current bit is 0
      maxLen = max(prevLen + currLen + 1, maxLen);
      prevLen = (x & 2) == 0 ? 0 : currLen;
      currLen = 0;
    }
    x >>= 1;
  }
  maxLen = max(prevLen + currLen + 1, maxLen);

  return maxLen;
}

int main()
{
  int x;
  cin >> x;
  int ret = longestSequence(x);
  cout << ret << endl;
  return 0;
}
