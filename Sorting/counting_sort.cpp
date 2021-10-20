#include <iostream>
using namespace std;

void countingSort(unsigned short A[], unsigned short B[], int max, int n)
{
    // array to record frequency of less than each element
    int C[max + 1];
    // initialization
    for (int i = 0; i <= max; i++)
        C[i] = 0;

    // count frequency of each element
    for (int i = 0; i < n; i++)
        C[A[i]]++;

    // add frequency of fewer than each element
    for (int i = 1; i <= max; i++)
        C[i] += C[i - 1];

    // sort with C
    // when sort from (n-1)th element, output becomes stable
    for (int i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int n, max = 0;
    unsigned short *A, *B;

    cin >> n;

    // MAX size of Array is 2000000 in this challenging.
    // when create array of sizeof(int), segmentation fault happens.
    A = (unsigned short *)malloc(sizeof(short) * n);
    B = (unsigned short *)malloc(sizeof(short) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (max < A[i])
            max = A[i];
    }

    countingSort(A, B, max, n);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << B[i];
    }
    cout << endl;

    free(A);
    free(B);

    return 0;
}
