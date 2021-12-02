#include <iostream>
using namespace std;

#define N 100

int main()
{
    int n, m;
    int M[N][N];
    bool rowHasZero = false;
    bool colHasZero = false;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
            if (M[i][j] == 0)
            {
                if (i == 0)
                {
                    rowHasZero = true;
                }
                if (j == 0)
                {
                    colHasZero = true;
                }
                // take a note of position of zero in the first row and the first column
                M[i][0] = 0;
                M[0][j] = 0;
            }
        }
    }

    // set zero in row other than first column
    for (int i = 1; i < n; i++)
    {
        if (M[i][0] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                M[i][j] = 0;
            }
        }
    }

    // set zero in column other than first row
    for (int j = 1; j < m; j++)
    {
        if (M[0][j] == 0)
        {
            for (int i = 1; i < n; i++)
            {
                M[i][j] = 0;
            }
        }
    }

    // set zero in the first row and first column
    if (colHasZero)
    {
        for (int i = 0; i < n; i++)
            M[i][0] = 0;
    }

    if (rowHasZero)
    {
        for (int j = 0; j < m; j++)
            M[0][j] = 0;
    }

    // output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != 0)
                cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}
