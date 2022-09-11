#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define N 8

void printBoard(vector<int> rows)
{
  cout << ">>>" << endl;
  // row
  for (int i = 0; i < N; i++)
  {
    // col
    for (int j = 0; j < N; j++)
    {
      if (rows[j] == i)
      {
        cout << "[x]";
      }
      else
      {
        cout << "[ ]";
      }
    }
    cout << endl;
  }
  cout << "<<<" << endl;
}

bool isInvalid(int row, int col, vector<int> rows)
{
  for (int i = 0; i < col; i++)
  {
    if (rows[i] == row)
    {
      return true;
    }

    int rowDiff = abs(rows[i] - row);
    int colDiff = abs(i - col);
    if (rowDiff == colDiff)
    {
      // if differences of x and y directions are same, two queens are on the same diagonal line.
      return true;
    }
  }
  return false;
}

int posQueen(int row, int col, vector<int> rows)
{
  if (col >= N)
  {
    return 0;
  }

  if (isInvalid(row, col, rows))
  {
    return 0;
  }

  rows.push_back(row);
  if (col == N - 1)
  {
    printBoard(rows);
    return 1;
  }

  int patterns = 0;
  // loop by rows
  for (int i = 0; i < N; i++)
  {
    patterns += posQueen(i, col + 1, rows);
  }
  return patterns;
}

int main()
{
  int rowMap = 0;
  vector<int> rows;
  int patterns = 0;

  // loop by rows
  for (int i = 0; i < N; i++)
  {
    patterns += posQueen(i, 0, rows);
  }
  cout << patterns << endl;

  return 0;
}
