#include <iostream>
using namespace std;

#define N 1000
#define NIL -1

int searchIndex(int *A, int left, int right, int target)
{
  // In this problem, given array is assumed to be sorted in ascending order, even after rotated
  if (left > right)
  {
    return NIL;
  }

  int mid = (left + right) / 2;
  if (A[mid] == target)
  {
    return mid;
  }

  // From here, it can be assumed that A[mid] is not equal to target.

  // Search left side, when it is possible that target is in left side.
  if (A[left] < A[mid])
  {
    if (A[left] <= target && target < A[mid])
    {
      return searchIndex(A, left, mid - 1, target);
    }
    else
    {
      return searchIndex(A, mid + 1, right, target);
    }
  }
  // Search right side, when it is possible that target is in right side.
  else if (A[left] > A[mid])
  {
    if (A[mid] < target && target <= A[right])
    {
      return searchIndex(A, mid + 1, right, target);
    }
    else
    {
      return searchIndex(A, left, mid - 1, target);
    }
  }
  // Search both sides, when target can be in any side.
  else
  {
    int result = searchIndex(A, mid + 1, right, target);
    if (result == NIL)
    {
      return searchIndex(A, left, mid - 1, target);
    }
    else
    {
      return result;
    }
  }
  return NIL;
}

int main()
{
  int A[N];
  int n, target;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  cin >> target;

  int result = searchIndex(A, 0, n - 1, target);
  if (result == NIL)
  {
    cout << "Could not find target" << endl;
  }
  else
  {
    cout << "Target Index: " << result << endl;
  }

  return 0;
}
