#include <iostream>
using namespace std;

#define N 100
#define NIL -1
#define MAX 2001

/*
    n: number of vertices
    M: adjacent matrix of graph
*/
int n, M[N][N];

// prim algorithm
int prim()
{
    /*
        V: array of flags whether a vertex is visited or not
        W: minimum weights between each vertex outside MST and one inside MST
        P: connected vertex in MST when vertex outside MST has connection to MST with minimum weight
    */
    int V[N], W[N], P[N];

    // initialization
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        W[i] = MAX;
        P[i] = NIL;
    }

    // start from index 0
    W[0] = 0;
    int count = 0;

    while (count < n)
    {
        int minW = MAX;
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
        count++;

        for (int v = 0; v < n; v++)
        {
            if (V[v] != 1 && M[u][v] != NIL)
            {
                if (W[v] > M[u][v])
                {
                    W[v] = M[u][v];
                    P[v] = u;
                }
            }
        }
    }
    // output result
    int sumW = 0;
    for (int i = 0; i < n; i++)
    {
        if (P[i] != NIL)
            sumW += W[i];
    }
    return sumW;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    }

    int ret = prim();
    cout << ret << endl;

    return 0;
}
