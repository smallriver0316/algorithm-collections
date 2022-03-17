#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

#define N 100
#define NIL -1
#define UNVISITED 0
#define VISITED 1

/*
  M: adjacent matrix
  A: characters of nodes
  V: whether ordered or not
*/
int n, M[N][N];
char A[N];
int V[N];

int findIndependentNodes(int order[], int offset)
{
  for (int j = 0; j < n; j++)
  {
    if (V[j] == VISITED)
    {
      continue;
    }

    bool isIndependent = true;
    for (int i = 0; i < n; i++)
    {
      if (M[i][j] == 1 && V[i] == UNVISITED)
      {
        isIndependent = false;
        break;
      }
    }
    if (isIndependent)
    {
      order[offset] = j;
      V[j] = VISITED;
      offset++;
    }
  }
  return offset;
}

void makeOrder(int order[])
{
  int offset = 0;

  while (offset < n)
  {
    offset = findIndependentNodes(order, offset);
  }
}

int main()
{
  char c, c1, c2;
  int k;
  unordered_map<char, int> key2index;

  cin >> n;

  // initialization
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

  int order[N];
  makeOrder(order);

  for (int i = 0; i < n; i++)
  {
    if (i > 0)
    {
      cout << " ";
    }
    cout << A[order[i]];
  }
  cout << endl;

  return 0;
}
