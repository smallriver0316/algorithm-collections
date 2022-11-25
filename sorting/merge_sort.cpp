#include <iostream>
using namespace std;

#define N 500000
#define INFTY (1 << 21)

int count = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];

    // initialization
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;

    // merge
    int l = 0, r = 0;
    for (int i = left; i < right; i++)
    {
        if (L[l] <= R[r])
        {
            A[i] = L[l];
            l++;
        }
        else
        {
            A[i] = R[r];
            r++;
        }
        count++;
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n, A[N];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n);

    // output result
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << A[i];
        else
            cout << " " << A[i];
    }
    cout << endl;

    // output number of comparison
    cout << count << endl;

    return 0;
}
