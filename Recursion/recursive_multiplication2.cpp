#include <iostream>
using namespace std;

int minProductHelper(int smaller, int bigger)
{
  if (smaller == 0)
  {
    return 0;
  }
  else if (smaller == 1)
  {
    return bigger;
  }
  else
  {
    // it assumes to count (smaller x bigger) boxes.
    // the number is double of the half, and the half is double of half of the half.
    // calculate it with recursion.

    // make half
    int s = smaller >> 1;
    // count half boxes
    int side1 = minProductHelper(s, bigger);
    // another side of half boxes
    int side2 = side1;
    // in case that the smaller is odd number
    if (smaller % 2 == 1)
    {
      // another side is (smaller - s).
      side2 = minProductHelper(smaller - s, bigger);
    }
    return side1 + side2;
  }
}

int minProduct(int x, int y)
{
  int bigger = x > y ? x : y;
  int smaller = x >= y ? y : x;
  return minProductHelper(smaller, bigger);
}

int main()
{
  int x, y;

  cin >> x >> y;

  int ret = minProduct(x, y);
  cout << "result: " << ret << endl;

  return 0;
}
