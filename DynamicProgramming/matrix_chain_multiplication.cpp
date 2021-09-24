#include <iostream>
#include <algorithm>
using namespace std;

#define N 100
#define INFTY (1 << 21)

/*
    p[i]: number of rows of i-th matrix (in this case, number of columns of i-th matrix is equal to number of rows of (i+1)-th matrix)
    M[i][j]: minimum number of matrix chain multiplication between i-th and j-th matrix
*/
int p[N + 1], M[N][N];

// calculate matrix chain multiplication
int calcMCM(int start, int end)
{
    if (M[start][end] != INFTY)
        return M[start][end];

    for (int k = start; k <= end; k++)
    {
        int mcm = calcMCM(start, k) + calcMCM(k + 1, end) + p[start] * p[k + 1] * p[end + 1];
        M[start][end] = min(M[start][end], mcm);
    }

    return M[start][end];
}

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i - 1] >> p[i];
    }

    // initialization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                M[i][j] = 0;
            else
                M[i][j] = INFTY;
        }
    }

    calcMCM(0, n - 1);
    cout << M[0][n - 1] << endl;

    return 0;
}
