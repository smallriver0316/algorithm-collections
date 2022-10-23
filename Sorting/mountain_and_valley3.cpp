#include <iostream>
using namespace std;

// See one element and two neighbors of both side
// if the middle element is larger than others, it will be mountain and others will be valley.
// So arrange as that the middle element become the largest of them.
void solve(int *A, int n)
{
  for (int i = 0; i < n - 1; i += 2)
  {
    if (A[i + 1] < A[i])
    {
      swap(A[i], A[i + 1]);
    }
    if (i + 2 < n && A[i + 1] < A[i + 2])
    {
      swap(A[i + 1], A[i + 2]);
    }
  }
}

int main()
{
  int n;

  cin >> n;

  int A[n];
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  solve(A, n);

  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}
