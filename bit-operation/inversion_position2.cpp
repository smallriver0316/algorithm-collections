#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_LEN 32

// push count of consecutive zero or one bit in order of count of zeros, count of ones, ...
vector<int> getAlternatingSequences(int x)
{
  vector<int> sequences;
  int searchingFor = 0;
  int counter = 0;

  for (int i = 0; i < MAX_LEN; i++)
  {
    if ((x & 1) != searchingFor)
    {
      sequences.push_back(counter);
      searchingFor = x & 1;
      counter = 0;
    }
    counter++;
    x >>= 1;
  }
  sequences.push_back(counter);

  return sequences;
}

int findLongestSequence(vector<int> seq)
{
  int maxSeq = 1;

  for (int i = 0; i < seq.size(); i += 2)
  {
    int zeroSeq = seq[i];
    int onesSeqRight = i - 1 >= 0 ? seq[i - 1] : 0;
    int onesSeqLeft = i + 1 < seq.size() ? seq[i + 1] : 0;

    int thisSeq = 0;
    if (zeroSeq == 1)
    {
      // when sequence of zero is sized 1, adjacent sequences of ones can be connected.
      thisSeq = onesSeqLeft + 1 + onesSeqRight;
    }
    else if (zeroSeq > 1)
    {
      // when sequence of zero is sized more than 1, longer ones among right and left will be selected and added 1.
      thisSeq = 1 + max(onesSeqLeft, onesSeqRight);
    }
    else if (zeroSeq == 0)
    {
      // when sequence of zero is sized 0, longer ones among right and left will be selected(one of them must be sized 0).
      thisSeq = max(onesSeqLeft, onesSeqRight);
    }
    maxSeq = max(maxSeq, thisSeq);
  }
  return maxSeq;
}

int longestSequence(int x)
{
  if (x == -1)
    return MAX_LEN;

  vector<int> sequences = getAlternatingSequences(x);

  return findLongestSequence(sequences);
}

int main()
{
  int x;
  cin >> x;
  int ret = longestSequence(x);
  cout << ret << endl;
  return 0;
}
