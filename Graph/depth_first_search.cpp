#include <iostream>
#include <stack>
using namespace std;

#define N 100
#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2

/*
    M: Adjacent Matrix of graph
    V: list of status whether visited in depth first search
    start: list of timestamps when each vertex is visited at first in search
    finish: list of timestamps when each veritex and its adjacent vertices are completed in search
*/
int n, M[N][N];
int V[N], start[N], finish[N];

int nextVertex(int uidx, int vidx)
{
    for (int i = vidx + 1; i < n; i++)
    {
        if (M[uidx][i] && V[i] == NOT_VISITED)
            return i;
    }
    return -1;
}

int dfsVisit(int index, int timestamp)
{
    stack<int> S;
    S.push(index);
    V[index] = VISITING;
    start[index] = ++timestamp;

    int u, v = 0;
    while (!S.empty())
    {
        u = S.top();
        v = nextVertex(u, v);
        if (v != -1)
        {
            V[v] = VISITING;
            start[v] = ++timestamp;
            S.push(v);
        }
        else
        {
            S.pop();
            V[u] = VISITED;
            finish[u] = ++timestamp;
        }
    }
    return timestamp;
}

void dfs()
{
    // initialization
    int timestamp = 0;
    for (int i = 0; i < n; i++)
        V[i] = NOT_VISITED;
    // calculation
    for (int i = 0; i < n; i++)
    {
        if (V[i] == NOT_VISITED)
            timestamp = dfsVisit(i, timestamp);
    }
    // output
    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << start[i] << " " << finish[i] << endl;
}

int main()
{
    int u, k, v;

    cin >> n;

    // initialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
    }

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        int uidx = u - 1;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            int vidx = v - 1;
            M[uidx][vidx] = 1;
        }
    }

    dfs();

    return 0;
}
