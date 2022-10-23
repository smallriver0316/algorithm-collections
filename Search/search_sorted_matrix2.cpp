#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Coordinate
{
public:
  int row, col;
  Coordinate(int r, int c)
  {
    row = r;
    col = c;
  }

  bool inbounds(vector<vector<int>> mat)
  {
    return row >= 0 && col >= 0 && row < mat.size() && col < mat.at(0).size();
  }

  bool isBefore(Coordinate x)
  {
    return row < x.row && col < x.col;
  }

  Coordinate clone()
  {
    return Coordinate(row, col);
  }

  void setToAverage(Coordinate min, Coordinate max)
  {
    row = (min.row + max.row) / 2;
    col = (min.col + max.col) / 2;
  }
};

Coordinate partitionAndSearch(vector<vector<int>> M, Coordinate org, Coordinate dst, Coordinate mid, int target);
Coordinate searchElem(vector<vector<int>> M, Coordinate org, Coordinate dst, int target);

Coordinate partitionAndSearch(vector<vector<int>> M, Coordinate org, Coordinate dst, Coordinate mid, int target)
{
  Coordinate lowerLeftOrg = Coordinate(mid.row, org.col);
  Coordinate lowerLeftDst = Coordinate(dst.row, mid.col - 1);
  Coordinate upperRightOrg = Coordinate(org.row, mid.col);
  Coordinate upperRightDst = Coordinate(mid.row - 1, dst.col);

  Coordinate ret = searchElem(M, lowerLeftOrg, lowerLeftDst, target);
  if (ret.col == -1 || ret.row == -1)
  {
    ret = searchElem(M, upperRightOrg, upperRightDst, target);
  }

  return ret;
}

Coordinate searchElem(vector<vector<int>> M, Coordinate org, Coordinate dst, int target)
{
  if (!org.inbounds(M) || !dst.inbounds(M))
  {
    return Coordinate(-1, -1);
  }
  if (M.at(org.row).at(org.col) == target)
  {
    return org;
  }
  if (!org.isBefore(dst))
  {
    return Coordinate(-1, -1);
  }

  Coordinate start = org.clone();

  int diff = std::min(dst.row - org.row, dst.col - org.col);
  Coordinate end = Coordinate(start.row + diff, start.col + diff);
  Coordinate mid = Coordinate(0, 0);

  while (start.isBefore(end))
  {
    mid.setToAverage(start, end);
    if (target > M.at(mid.row).at(mid.col))
    {
      // The value at start coordinate will be larger than target
      start.row = mid.row + 1;
      start.col = mid.col + 1;
    }
    else if (target < M.at(mid.row).at(mid.col))
    {
      end.row = mid.row - 1;
      end.col = mid.col - 1;
    }
    else
    {
      return mid;
    }
  }

  // Specify start as mid position
  // the value at start coordinate is expected to be the first value which is larger than target in diagonal values in matrix
  return partitionAndSearch(M, org, dst, start, target);
}

Coordinate searchHelper(vector<vector<int>> M, int target)
{
  Coordinate org = Coordinate(0, 0);
  Coordinate dst = Coordinate(M.size() - 1, M.at(0).size() - 1);
  return searchElem(M, org, dst, target);
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

  Coordinate ret = searchHelper(M, x);

  if (ret.col == -1 || ret.row == -1)
  {
    cout << "Could not find target" << endl;
  }
  else
  {
    cout << ret.row << " row, " << ret.col << " column" << endl;
  }

  return 0;
}
