#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000

void merge(int *A, int *B, int n1, int n2)
{
  int last = n1 + n2 - 1;
  int p1 = n1 - 1;
  int p2 = n2 - 1;
  while (p1 >= 0 && p2 >= 0)
  {
    if (A[p1] >= B[p2])
    {
      A[last] = A[p1];
      p1--;
    }
    else
    {
      A[last] = B[p2];
      p2--;
    }
    last--;
  }

  // copy remained
  for (; p1 >= 0; p1--)
  {
    A[last--] = A[p1];
  }
  for (; p2 >= 0; p2--)
  {
    A[last--] = B[p2];
  }
}

int main()
{
  int n1, n2;
  int A[N], B[N];

  cin >> n1;
  for (int i = 0; i < n1; i++)
  {
    cin >> A[i];
  }

  cin >> n2;
  for (int i = 0; i < n2; i++)
  {
    cin >> B[i];
  }

  // sort just to make sure
  sort(A, A + n1);
  sort(B, B + n2);

  merge(A, B, n1, n2);

  // print
  for (int i = 0; i < n1 + n2; i++)
  {
    cout << A[i] << ", ";
  }
  cout << endl;

  return 0;
}
