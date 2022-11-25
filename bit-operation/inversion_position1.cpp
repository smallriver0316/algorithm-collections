#include <iostream>
#include <vector>
using namespace std;

int solve(int x)
{
  // record positions of zero
  vector<int> zeros;
  int length = 0;

  while ((x >> length) > 0)
  {
    if (!((x >> length) & 1))
    {
      zeros.push_back(length);
    }
    length++;
  }

  if (zeros.size() == 0)
  {
    return length;
  }

  int max = 0;
  int prev, curr, next;
  int len;
  for (vector<int>::iterator it = zeros.begin(); it != zeros.end(); it++)
  {
    // current position of zero
    curr = *it;

    // previous position of zero
    if (it == zeros.begin())
    {
      prev = -1;
    }
    else
    {
      prev = *(it - 1);
    }

    // next position of zero
    if (it == (zeros.end() - 1))
    {
      next = length;
    }
    else
    {
      next = *(it + 1);
    }

    len = ((curr - prev - 1 > 0) ? (curr - prev - 1) : 0) + ((next - curr - 1 > 0) ? (next - curr - 1) : 0) + 1;
    if (len > max)
    {
      max = len;
    }
  }

  return max;
}

int main()
{
  int x;
  cin >> x;
  int ret = solve(x);
  cout << ret << endl;
  return 0;
}
