#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define N 10000
#define MAX_WEIGHT 100000
#define INFTY (1 << 20)

typedef pair<int, int> pi;

int n;
vector<pi> adj[N]; // adjacent list of oriented graph with weight

void dijkstra()
{
    /*
        PQ: priority queue in ascending order
        W: minimum weight between vertex 0 and another
        V: array of flags whether a vertex is visited or not
    */
    priority_queue<pi, std::vector<pi>, std::greater<pi>> PQ;
    int V[N], W[N];

    for (int i = 0; i < n; i++)
    {
        W[i] = INFTY;
        V[i] = 0;
    }

    W[0] = 0;
    PQ.push(make_pair(0, 0));

    while (!PQ.empty())
    {
        pi f = PQ.top();
        PQ.pop();
        int u = f.second;
        V[u] = 1;

        if (W[u] < f.first)
            continue;

        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].first;
            if (V[v] == 1)
                continue;
            if (W[v] > W[u] + adj[u][j].second)
            {
                W[v] = W[u] + adj[u][j].second;
                PQ.push(make_pair(W[v], v));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << (W[i] == INFTY ? -1 : W[i]) << endl;
    }
}

int main()
{
    int k, u, v, w;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v >> w;
            adj[u].push_back(make_pair(v, w));
        }
    }

    dijkstra();

    return 0;
}
