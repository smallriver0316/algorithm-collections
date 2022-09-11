#include <iostream>
using namespace std;

#define N 1000

int A[N];

int findMagicIndex(int start, int end)
{
  if (start == end)
  {
    if (A[start] == start)
    {
      return start;
    }
    else
    {
      return -1;
    }
  }

  int mid = (start + end) / 2;
  if (A[mid] == mid)
  {
    return mid;
  }
  else if (A[mid] > mid)
  {
    return findMagicIndex(start, mid);
  }
  else
  {
    return findMagicIndex(mid, end);
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

  int ret = findMagicIndex(0, n - 1);
  if (ret == -1)
  {
    cout << "Could not find magic index" << endl;
  }
  else
  {
    cout << ret << endl;
  }

  return 0;
}
