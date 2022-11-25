#include <iostream>
#include <vector>
using namespace std;

#define NIL -1

int findIndex(vector<string> array, string target, int leftIndex, int rightIndex)
{
  if (leftIndex > rightIndex)
  {
    return NIL;
  }

  int mid = (leftIndex + rightIndex) / 2;
  if (array[mid] == "")
  {
    int md1 = mid, md2 = mid;
    while (array[md1] == "" && array[md2] == "" && md1 > leftIndex && md2 < rightIndex)
    {
      md1--;
      md2++;
    }

    if (array[md1] != "" && md1 != leftIndex)
    {
      mid = md1;
    }
    else if (array[md2] != "" && md2 != rightIndex)
    {
      mid = md2;
    }
    else if (md1 == leftIndex && md2 != rightIndex)
    {
      if (array[md1] == target)
      {
        return md1;
      }
      else
      {
        mid = md2;
      }
    }
    else
    {
      if (array[md2] == target)
      {
        return md2;
      }
      else
      {
        mid = md1;
      }
    }
  }

  if (array[mid] == target)
  {
    return mid;
  }

  if (array[mid] > target)
  {
    return findIndex(array, target, leftIndex, mid - 1);
  }

  if (array[mid] < target)
  {
    return findIndex(array, target, mid + 1, rightIndex);
  }

  return NIL;
}

int main()
{
  int n;
  string s, target;
  int space;
  vector<string> array;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> space;
    array.push_back(s);
    for (int j = 0; j < space; j++)
    {
      array.push_back("");
    }
  }

  // show array
  for (vector<string>::iterator it = array.begin(); it != array.end(); it++)
  {
    cout << "\"" << *it << "\", ";
  }
  cout << endl;

  cin >> target;

  int ret = findIndex(array, target, 0, array.size() - 1);

  if (ret == NIL)
  {
    cout << "Could not find index." << endl;
  }
  else
  {
    cout << "Target index is " << ret << " th index." << endl;
  }

  return 0;
}
