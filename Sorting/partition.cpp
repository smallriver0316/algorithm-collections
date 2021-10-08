#include <iostream>
using namespace std;

#define N 100000

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);

    return i;
}

int main()
{
    int n, q, A[N + 1];

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    q = partition(A, 1, n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        if (i == q)
            cout << "[" << A[i] << "]";
        else
            cout << A[i];
    }
    cout << endl;

    return 0;
}
