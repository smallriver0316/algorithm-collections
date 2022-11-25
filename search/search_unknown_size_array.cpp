#include <iostream>
#include <unordered_map>
using namespace std;

#define NIL -1

class UnknownSizeArray
{
  unordered_map<int, int> array_map;
  int size;

public:
  UnknownSizeArray()
  {
    size = 0;
  }

  void add(int x)
  {
    array_map[size] = x;
    size++;
  }

  int elementAt(int index)
  {
    if (index >= size)
    {
      return NIL;
    }
    else
    {
      return array_map[index];
    }
  }
};

int findIndex(UnknownSizeArray *array, int target, int leftIndex, int rightIndex)
{
  int leftItem = array->elementAt(leftIndex);
  int rightItem = array->elementAt(rightIndex);

  if (leftItem == NIL)
  {
    return NIL;
  }

  if (leftItem == target)
  {
    return leftIndex;
  }

  if (rightItem == target)
  {
    return rightIndex;
  }

  if (rightItem == NIL)
  {
    return findIndex(array, target, leftIndex, rightIndex - (rightIndex - leftIndex) / 2);
  }

  if (rightItem < target)
  {
    return findIndex(array, target, rightIndex, rightIndex * 2);
  }

  int midIndex = (leftIndex + rightIndex) / 2;
  int midItem = array->elementAt(midIndex);
  if (midItem >= target)
  {
    return findIndex(array, target, leftIndex, midIndex);
  }
  else
  {
    return findIndex(array, target, midIndex, rightIndex);
  }
}

int main()
{
  int n, a, x;
  UnknownSizeArray array;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    array.add(a);
  }

  cin >> x;
  int targetIndex = findIndex(&array, x, 0, 1);

  if (targetIndex == NIL)
  {
    cout << "Could not find target index." << endl;
  }
  else
  {
    cout << targetIndex << endl;
  }

  return 0;
}
