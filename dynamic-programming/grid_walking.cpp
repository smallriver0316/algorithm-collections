#include <iostream>
using namespace std;

#define N 100
#define UNKNOWN 0
#define AVAILABLE 1
#define NON_AVAILABLE 2

int G[N][N];

void makeMap(int r, int c)
{
  for (int i = r - 1; i >= 0; i--)
  {
    for (int j = c - 1; j >= 0; j--)
    {
      // goal must be available
      if (i == r - 1 && j == c - 1)
      {
        G[i][j] = AVAILABLE;
      }
      // others
      if (G[i][j] == UNKNOWN)
      {
        if ((i < r - 1 && G[i + 1][j] == AVAILABLE) || (j < c - 1 && G[i][j + 1] == AVAILABLE))
        {
          G[i][j] = AVAILABLE;
        }
      }
    }
  }
}

void printRoute(int r, int c)
{
  int i = 0;
  int j = 0;

  while (i < r - 1 || j < c - 1)
  {
    if (i < r - 1 && G[i + 1][j] == AVAILABLE)
    {
      i++;
      cout << "↓ ";
    }
    else if (j < c - 1 && G[i][j + 1] == AVAILABLE)
    {
      j++;
      cout << "→ ";
    }
  }
  cout << endl;
}

int main()
{
  int r, c;

  cin >> r >> c;

  // initialize
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      G[i][j] = UNKNOWN;
    }
  }

  // mapping non-available
  int k, x, y;

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x >> y;
    G[x][y] = NON_AVAILABLE;
  }

  makeMap(r, c);

  printRoute(r, c);

  return 0;
}
