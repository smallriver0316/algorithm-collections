#include <iostream>
using namespace std;

#define NMAX 20
#define MMAX 2000

/*
    n: length of input array
    A: input array
    X: results of exhaustive search; array of 1 or 0
*/
int n, A[NMAX];
bool X[NMAX][MMAX];

// Bubble Sort
void sortAscend()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

bool exhaustiveSearch(int index, int m)
{
    if (X[index][m])
        return true;

    if (index >= n)
        X[index][m] = false;
    else if (m == 0)
        X[index][m] = true;
    else if (exhaustiveSearch(index + 1, m - A[index]))
        X[index][m] = true;
    else if (exhaustiveSearch(index + 1, m))
        X[index][m] = true;

    return X[index][m];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // initialize X[][]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MMAX; j++)
        {
            X[i][j] = false;
        }
    }

    sortAscend();

    int q, m;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        if (exhaustiveSearch(0, m))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
