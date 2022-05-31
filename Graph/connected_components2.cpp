#include <iostream>
#include <stack>
using namespace std;

#define N 100
#define NIL -1
#define UNVISIT 0
#define VISITING 1
#define VISITED 2

int n, M[N][N], V[N];

int nextVertex(int uidx, int vidx)
{
  for (int i = vidx + 1; i < n; i++)
  {
    if (M[uidx][i] && V[i] == UNVISIT)
    {
      return i;
    }
  }
  return -1;
}

bool runDFS(int index1, int index2)
{
  stack<int> S;
  S.push(index1);
  V[index1] = VISITING;

  for (int i = 0; i < n; i++)
  {
    V[i] = UNVISIT;
  }

  int u, v = 0;
  while (!S.empty())
  {
    u = S.top();
    v = nextVertex(u, v);
    if (v != -1)
    {
      if (v == index2)
      {
        return true;
      }
      V[v] = VISITING;
      S.push(v);
    }
    else
    {
      S.pop();
      V[u] = VISITED;
    }
  }
  return false;
}

int main()
{
  int u, k, v, q, s, t;

  cin >> n;

  // initialization
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      M[i][j] = 0;
    }
  }

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> u >> k;
    for (int j = 0; j < k; j++)
    {
      cin >> v;
      M[u - 1][v - 1] = 1;
    }
  }

  cin >> q;

  for (int i = 0; i < q; i++)
  {
    cin >> s >> t;
    if (runDFS(s - 1, t - 1))
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}
