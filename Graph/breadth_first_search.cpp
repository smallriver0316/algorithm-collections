#include <iostream>
#include <queue>
using namespace std;

#define N 100
#define INFIFTY -1

/*
    M: Adjacent Matrix of graph
    d: distances
*/
int n, M[N][N], d[N];

void bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    // initialization
    for (int i = 0; i < n; i++)
        d[i] = INFIFTY;
    d[s] = 0;

    int u;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (int v = 0; v < n; v++)
        {
            if (M[u][v] == 1 && d[v] == INFIFTY)
            {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << d[i] << endl;
    }
}

int main()
{
    int u, k, v;

    cin >> n;
    // initialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        int uidx = --u;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            int vidx = --v;
            M[uidx][vidx] = 1;
        }
    }

    bfs(0);

    return 0;
}
