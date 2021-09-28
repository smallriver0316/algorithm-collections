#include <iostream>
using namespace std;

#define N 100

int n, A[N];

void printArray()
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << A[i];
        else
            cout << " " << A[i];
    }
    cout << endl;
}

void insertionSort()
{
    for (int i = 1; i < n; i++)
    {
        int v = A[i];
        int j = i - 1;
        /*
            A[0:j] is sorted array.
            So if there are larger elements than A[i], they must be in upper side of [0:j].
            Therefore, it is possible to rearrange array in [0:j] without overwriting datum.
        */
        for (; j >= 0, A[j] > v; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = v;
        printArray();
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    printArray();
    insertionSort();

    return 0;
}
