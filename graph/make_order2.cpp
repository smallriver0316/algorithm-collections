#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

#define N 100
#define NIL -1
#define UNVISITED 0
#define VISITING 1
#define VISITED 2

int n, M[N][N];
char A[N];
int V[N];

int nextVertex(int u, int v)
{
  for (int i = v; i < n; i++)
  {
    if (M[u][i] && V[i] == UNVISITED)
    {
      return i;
    }
  }
  return NIL;
}

stack<int> runDFS(int index, stack<int> S)
{
  int v = 0;
  V[index] = VISITING;
  while ((v = nextVertex(index, v)) != NIL)
  {
    S = runDFS(v, S);
  }

  V[index] = VISITED;
  S.push(index);

  return S;
}

stack<int> makeOrder()
{
  stack<int> S;
  for (int i = 0; i < n; i++)
  {
    if (V[i] == UNVISITED)
    {
      S = runDFS(i, S);
    }
  }

  return S;
}

int main()
{
  char c, c1, c2;
  int k;
  unordered_map<char, int> key2index;

  cin >> n;

  // initilization
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      M[i][j] = 0;
    }
    V[i] = UNVISITED;
  }

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    A[i] = c;
    key2index[c] = i;
  }

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> c1 >> c2;
    int idx1 = key2index[c1];
    int idx2 = key2index[c2];
    M[idx2][idx1] = 1;
  }

  stack<int> S = makeOrder();

  while (!S.empty())
  {
    cout << A[S.top()] << " ";
    S.pop();
  }
  cout << endl;

  return 0;
}
