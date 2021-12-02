#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100

int M[N][N];
vector<int> Col, Row;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
            if (M[i][j] == 0)
            {
                Row.push_back(i);
                Col.push_back(j);
            }
        }
    }

    unique(Row.begin(), Row.end());
    unique(Col.begin(), Col.end());

    for (int i = 0; i < Row.size(); i++)
    {
        int row = Row[i];
        for (int j = 0; j < m; j++)
        {
            M[row][j] = 0;
        }
    }
    for (int j = 0; j < Col.size(); j++)
    {
        int col = Col[j];
        for (int i = 0; i < n; i++)
        {
            M[i][col] = 0;
        }
    }

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
