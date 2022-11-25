#include <iostream>
using namespace std;

#define N 200000
#define SENTINEL (2 << 9)
typedef long long llong;

int L[N / 2 + 2],
    R[N / 2 + 2];

llong merge(int A[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + i];

    L[n1] = R[n2] = SENTINEL;

    llong count = 0;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
            // sum of (n1 -i) per insertion of right side elements is number of inversion
            count += (n1 - i);
        }
    }
    return count;
}

llong mergeSort(int A[], int n, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        llong v1, v2, v3;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    }
    return 0;
}

int main()
{
    int n, A[N];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    llong ans = mergeSort(A, n, 0, n);
    cout << ans << endl;

    return 0;
}
