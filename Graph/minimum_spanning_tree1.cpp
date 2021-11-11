#include <iostream>
#include <vector>
using namespace std;

#define N 100
#define NIL -1
#define MAX 2001

/*
    n: number of vertices
    M: adjacent matrix of graph
    V: array of flags whether a vertex is visited or not
*/
int n, M[N][N], V[N];

int searchMST(int s)
{
    int sumW = 0;    // sum of weight in minimum spanning tree(MST)
    vector<int> mst; // vertices included in MST
    mst.push_back(s);

    // initilization
    for (int i = 0; i < n; i++)
        V[i] = 0;
    V[s] = 1;

    while (mst.size() < n)
    {
        int minW = MAX;
        int nextIdx = NIL;
        for (int i = 0; i < mst.size(); i++)
        {
            for (int v = 0; v < n; v++)
            {
                int u = mst[i];
                if (M[u][v] != NIL && V[v] == 0)
                {
                    if (minW > M[u][v])
                    {
                        minW = M[u][v];
                        nextIdx = v;
                    }
                }
            }
        }
        if (nextIdx != NIL)
        {
            mst.push_back(nextIdx);
            V[nextIdx] = 1;
            sumW += minW;
        }
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

    int ret = searchMST(0);
    cout << ret << endl;

    return 0;
}
