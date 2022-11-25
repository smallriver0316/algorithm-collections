#include <iostream>
using namespace std;

#define N 100

int n, A[N];

void bubbleSort()
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                count++;
            }
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

    bubbleSort();

    return 0;
}
