#include <iostream>
using namespace std;

#define N 100
#define UNKNOWN 0
#define UNAVAILABLE -1
#define AVAILABLE 1

int G[N][N];
int r, c;

bool walkGrid(int x, int y)
{
  if (G[x][y] == AVAILABLE)
  {
    return true;
  }
  if (G[x][y] == UNAVAILABLE)
  {
    return false;
  }

  // in case of UNKNOWN
  int ret;
  if (x == r - 1 && y == c - 1)
  {
    // goal must be available
    ret = true;
  }
  else if (x == r - 1 && y < c - 1)
  {
    ret = walkGrid(x, y + 1) == AVAILABLE;
  }
  else if (x < r - 1 && y == c - 1)
  {
    ret = walkGrid(x + 1, y) == AVAILABLE;
  }
  else
  {
    ret = walkGrid(x + 1, y) == AVAILABLE || walkGrid(x, y + 1) == AVAILABLE;
  }

  if (ret == true)
  {
    G[x][y] = AVAILABLE;
  }
  else
  {
    G[x][y] = UNAVAILABLE;
  }

  return ret;
}

void printGrid()
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cout << G[i][j] << " ";
    }
    cout << endl;
  }
}

void printRoute()
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
    else
    {
      cout << "Cannot reach the goal" << endl;
      printGrid();
      break;
    }
  }
  cout << endl;
}

int main()
{
  cin >> r >> c;

  // initialize
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      G[i][j] = UNKNOWN;
    }
  }

  int k, x, y;

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x >> y;
    G[x][y] = UNAVAILABLE;
  }

  walkGrid(0, 0);

  printRoute();

  return 0;
}
