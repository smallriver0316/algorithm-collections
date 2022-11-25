#include <iostream>
#include <vector>
using namespace std;

struct Result
{
  int row, col;
};

Result searchElem(vector<vector<int>> M, int rowStart, int rowEnd, int colStart, int colEnd, int target)
{
  if (rowStart > rowEnd || colStart > colEnd)
  {
    return {-1, -1};
  }
  if (rowStart == rowEnd && colStart == colEnd && M.at(rowStart).at(colStart) != target)
  {
    return {-1, -1};
  }

  int rowMid = (rowStart + rowEnd) / 2;
  int colMid = (colStart + colEnd) / 2;

  if (M.at(rowMid).at(colMid) == target)
  {
    return {row : rowMid, col : colMid};
  }

  if (M.at(rowMid).at(colMid) > target)
  {
    Result ret = searchElem(M, rowStart, rowMid - 1, colStart, colMid, target);
    if (ret.col == -1 || ret.row == -1)
    {
      // It has already been configured out that target is not in rowStart ~ rowMid - 1.
      // So it must be in the row of rowMid.
      ret = searchElem(M, rowMid, rowMid, colStart, colMid - 1, target);
    }
    return ret;
  }

  // if A.at(rowMid).at(colMid) < target
  Result ret = searchElem(M, rowMid + 1, rowEnd, colStart, colEnd, target);
  if (ret.col == -1 || ret.row == -1)
  {
    ret = searchElem(M, rowStart, rowEnd, colMid + 1, colEnd, target);
  }
  return ret;
}

Result searchHelper(vector<vector<int>> M, int rowNum, int colNum, int target)
{
  int colLim = colNum - 1;
  for (int i = colNum - 1; i >= 0; i--)
  {
    if (M.at(0).at(i) <= target && M.at(rowNum - 1).at(i) >= target)
    {
      colLim = i;
      break;
    }
  }

  int rowLim = rowNum - 1;
  for (int i = rowNum - 1; i >= 0; i--)
  {
    if (M.at(i).at(0) <= target && M.at(i).at(colLim) >= target)
    {
      rowLim = i;
      break;
    }
  }

  return searchElem(M, 0, rowLim, 0, colLim, target);
}

int main()
{
  int n, m;

  cin >> n >> m;

  vector<vector<int>> M(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> M.at(i).at(j);
    }
  }

  int x;
  cin >> x;

  Result ret = searchHelper(M, n, m, x);

  if (ret.col == -1 || ret.row == -1)
  {
    cout << "Could not find target" << endl;
  }
  else
  {
    cout << ret.row << " row, " << ret.col << " columns" << endl;
  }

  return 0;
}
