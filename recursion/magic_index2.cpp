#include <iostream>
#include <vector>
using namespace std;

#define N 1000

int A[N];

void findMagicIndex(int start, int end, vector<int> &ret)
{
  if (start == end)
  {
    if (A[start] == start)
    {
      ret.push_back(start);
    }
    return;
  }

  int mid = (start + end) / 2;
  if (A[mid] == mid)
  {
    ret.push_back(mid);
  }
  if (mid > start)
  {
    findMagicIndex(start, mid - 1, ret);
  }
  if (mid < end)
  {
    findMagicIndex(mid + 1, end, ret);
  }
}

int main()
{
  int n;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  vector<int> ret;

  findMagicIndex(0, n - 1, ret);
  if (ret.size() == 0)
  {
    cout << "Could not find magic index" << endl;
  }
  else
  {
    for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}
