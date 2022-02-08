#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 100000
#define NIL -1

/*
    n: number of vertices
    G: adjacent list of Graph
    V: array of group which includes reachable vertices
*/
int n;
vector<int> G[N];
int V[N];

void dfsVisit(int index, int group)
{
    stack<int> S;
    S.push(index);
    V[index] = group;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (V[v] == NIL)
            {
                V[v] = group;
                S.push(v);
            }
        }
    }
}

void dfs()
{
    // initialization
    // group ID
    int group = 1;
    for (int i = 0; i < n; i++)
        V[i] = NIL;
    // calculation
    for (int i = 0; i < n; i++)
    {
        if (V[i] == NIL)
            dfsVisit(i, group++);
    }
}

int main()
{
    /*
        m: number of connection between two vertices
        q: number of question whether given pair of vertices are reachable
        s, t: vertices of connected
    */
    int m, q, s, t;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs();

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> s >> t;
        if (V[s] == V[t])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
