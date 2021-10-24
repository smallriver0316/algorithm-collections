#include <iostream>
using namespace std;

#define N 100

int n, A[N];

void selectionSort()
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
        {
            count++;
            swap(A[i], A[minIdx]);
        }
    }

    // output result
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << A[i];
        else
            cout << " " << A[i];
    }
    cout << endl;
    cout << count << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    selectionSort();

    return 0;
}
