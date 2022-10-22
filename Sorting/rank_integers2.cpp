#include <iostream>
using namespace std;

class RankNode
{
  int data;
  int leftSize;
  RankNode *left;
  RankNode *right;

public:
  RankNode(int x)
  {
    data = x;
    leftSize = 0;
    left = nullptr;
    right = nullptr;
  }

  void insert(int x)
  {
    /*
      In the case of reading a duplicated number:
      if node == duplicated number => not increase rank of the node
      if node < duplicated number => not increase rank of the node
      if node > duplicated number => increase rank of the node
      So move duplicated number to right side.
    */
    if (x >= data)
    {
      if (right == nullptr)
      {
        right = (RankNode *)malloc(sizeof(RankNode));
        *right = RankNode(x);
      }
      else
      {
        right->insert(x);
      }
    }
    else
    {
      leftSize++;
      if (left == nullptr)
      {
        left = (RankNode *)malloc(sizeof(RankNode));
        *left = RankNode(x);
      }
      else
      {
        left->insert(x);
      }
    }
  }

  int getRank(int x)
  {
    if (x == data)
    {
      return leftSize;
    }
    else if (x < data)
    {
      return (left == nullptr ? 0 : left->getRank(x));
    }
    else
    {
      // if x > data
      // right side may include less number than x
      // add 1 as count of this node
      return leftSize + (right == nullptr ? 0 : right->getRank(x)) + 1;
    }
  }
};

RankNode *track(int x, RankNode *node)
{
  if (node == nullptr)
  {
    node = (RankNode *)malloc(sizeof(RankNode));
    *node = RankNode(x);
  }
  else
  {
    node->insert(x);
  }
  return node;
}

int getRankOfNumber(int x, RankNode *node)
{
  if (node == nullptr)
  {
    return -1;
  }
  else
  {
    return node->getRank(x);
  }
}

int main()
{
  int n, x;
  RankNode *root = nullptr;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    root = track(x, root);
  }

  int m, ret;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    ret = getRankOfNumber(x, root);
    if (ret == -1)
    {
      cout << "Not found such number!" << endl;
    }
    else
    {
      cout << ret << endl;
    }
  }

  return 0;
}
