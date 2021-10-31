#include <iostream>
#include <stack>
using namespace std;

#define N 100
#define NOT_VISITED 0
#define UNDER_VISITING 1
#define FINISH_VISITED 2

int n, Adj[N][N];
int visit[N], start[N], finish[N];

int nextVertex(int uidx, int vidx)
{
    for (int i = vidx + 1; i < n; i++)
    {
        if (Adj[uidx][i] && visit[i] == NOT_VISITED)
            return i;
    }
    return -1;
}

int dfsVisit(int index, int timestamp)
{
    stack<int> S;
    S.push(index);
    visit[index] = UNDER_VISITING;
    start[index] = ++timestamp;

    int u, v = 0;
    while (!S.empty())
    {
        u = S.top();
        v = nextVertex(u, v);
        if (v != -1)
        {
            visit[v] = UNDER_VISITING;
            start[v] = ++timestamp;
            S.push(v);
        }
        else
        {
            S.pop();
            visit[u] = FINISH_VISITED;
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
        visit[i] = NOT_VISITED;
    // calculation
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == NOT_VISITED)
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
            Adj[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        int uidx = u - 1;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            int vidx = v - 1;
            Adj[uidx][vidx] = 1;
        }
    }

    dfs();

    return 0;
}
