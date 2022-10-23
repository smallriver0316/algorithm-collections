#include <iostream>
#include <algorithm>
using namespace std;

void solve(int *A, int n)
{
  sort(A, A + n, greater<int>());

  // j is index of next valley
  int tmp, j = n - 1;
  for (int i = 1; i <= j; i++)
  {
    tmp = A[i];
    if (i % 2 == 1)
    {
      // valley
      // A[j] has the smallest number in rearranged part(index i ~).
      // So it must become valley.
      A[i] = A[j];
      A[j] = tmp;
      j--;
    }
    else
    {
      // mountain
      // A[n - 1] has the maximum number in rearranged part(index i ~).
      // So it must become mountain.
      A[i] = A[n - 1];
      A[n - 1] = tmp;
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
