#include <iostream>
using namespace std;

#define N 100
#define MAX_WEIGHT 100000
#define NIL -1
#define INFTY (1 << 21)

int n, M[N][N];

void dijkstra()
{
    /*
        W: minimum weight between vertex 0 and another
        V: array of flags whether a vertex is visited or not
    */
    int V[N], W[N];
    int minW;

    // initilization
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        W[i] = INFTY;
    }

    // start from 0
    W[0] = 0;
    while (1)
    {
        minW = INFTY;
        int u = NIL;
        for (int i = 0; i < n; i++)
        {
            if (minW > W[i] && V[i] != 1)
            {
                u = i;
                minW = W[i];
            }
        }

        if (u == NIL)
            break;

        V[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (V[v] != 1 && M[u][v] != INFTY)
            {
                if (W[v] > W[u] + M[u][v])
                    W[v] = W[u] + M[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << (W[i] == INFTY ? -1 : W[i]) << endl;
}

int main()
{
    /*
        u: vertex
        k: number of connections against vertex u
        v: vertex connected from vertex u
        w: weight between vertex u and v
    */
    int u, k, v, w;

    cin >> n;
    // initialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = INFTY;
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

    dijkstra();

    return 0;
}
