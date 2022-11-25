#include <iostream>
using namespace std;

#define N 100

int n;
int M[N][N];

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != 0)
                cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}

void rotate()
{
    if (n < 2)
        return;

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int top = M[first][i];
            M[first][i] = M[last - offset][first];
            M[last - offset][first] = M[last][last - offset];
            M[last][last - offset] = M[i][last];
            M[i][last] = top;
        }
    }
}

int main()
{
    cin >> n;

    // input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    }

    rotate();
    output();

    return 0;
}
