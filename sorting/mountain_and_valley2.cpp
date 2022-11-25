#include <iostream>
#include <algorithm>
using namespace std;

void solve(int *A, int n)
{
  sort(A, A + n);

  // Sorted numbers are arranged as small -> medium -> large.
  // So rearrange them as medium -> small -> large
  for (int i = 0; i < n - 1; i += 2)
  {
    swap(A[i], A[i + 1]);
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
