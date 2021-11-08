#include <iostream>
#include <vector>
using namespace std;

#define N 100
#define MAX_WEIGHT 100000
#define NIL -1
#define INFTY (1 << 21)

/*
    n: number of vertices
    M: adjacent matrix of graph which records weight of each edge
*/
int n, M[N][N];

void solve()
{
    /*
        W: minimum weight between vertex 0 and another
    */
    int W[N];
    vector<int> s3p; // single source shortest path

    // initialization
    for (int i = 0; i < n; i++)
        W[i] = INFTY;

    W[0] = 0;
    s3p.push_back(0);

    while (s3p.size() < n)
    {
        for (int v = 1; v < n; v++)
        {
            int minW = INFTY; // minimum weight from vertex 0 to v
            for (int i = 0; i < s3p.size(); i++)
            {
                int u = s3p[i];
                if (M[u][v] != NIL && W[v] == INFTY)
                {
                    if (minW > M[u][v] + W[u])
                        minW = M[u][v] + W[u];
                }
            }
            if (minW != INFTY)
            {
                s3p.push_back(v);
                W[v] = minW;
            }
            else
                break;
        }
    }

    // output
    for (int i = 0; i < n; i++)
        cout << i << " " << W[i] << endl;
}

int main()
{
    // initilization
    /*
        u: vertex
        k: number of connections against vertex u
        v: vertex connected from vertex u
        w: weight between vertex u and v
    */
    int u, k, v, w;

    cin >> n;
    // initilization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = NIL;
        }
    }
    // read inputs
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v >> w;
            M[u][v] = w;
        }
    }

    solve();

    return 0;
}
