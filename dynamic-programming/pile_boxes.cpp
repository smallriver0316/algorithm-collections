#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box
{
  int wi, hi, di;
};

int pileBoxesHelper(vector<Box> boxes, Box prev, int index, int offset, int *Memo)
{
  if (index >= boxes.size())
  {
    return 0;
  }

  if (Memo[index] > 0)
  {
    return Memo[index];
  }

  Box b = boxes[index];
  int result = 0;

  if (offset == 0 || (b.wi < prev.wi && b.hi < prev.hi && b.di < prev.di))
  {
    result += b.hi;
    prev = b;
  }

  result += pileBoxesHelper(boxes, prev, index + 1, offset + 1, Memo);
  Memo[index] = result;

  return result;
}

int pileBoxes(vector<Box> boxes, int n)
{
  int result = 0;

  int Memo[n];
  for (int i = 0; i < n; i++)
  {
    Memo[i] = 0;
  }

  for (int i = 0; i < boxes.size(); i++)
  {
    Box b;
    int ret = pileBoxesHelper(boxes, b, i, 0, Memo);
    if (ret > result)
    {
      result = ret;
    }
  }

  return result;
}

int main()
{
  int n;
  vector<Box> boxes;
  cin >> n;

  int wi, hi, di;
  for (int i = 0; i < n; i++)
  {
    cin >> wi >> hi >> di;
    Box b = {wi, hi, di};
    boxes.push_back(b);
  }

  sort(boxes.begin(), boxes.end(), [](Box a, Box b)
       { return a.hi > b.hi; });

  int ret = pileBoxes(boxes, n);
  cout << ret << endl;

  return 0;
}
