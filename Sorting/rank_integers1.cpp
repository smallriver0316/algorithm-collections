#include <iostream>
using namespace std;

struct Node
{
  int key;
  int value;
  Node *left, *right;
};

class Rank
{
  Node *root;
  int size;

public:
  Rank()
  {
    root = (Node *)malloc(sizeof(Node));
    size = 0;
  }

  Node *createNode(int x)
  {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = x;
    node->value = 1;
    node->left = nullptr;
    node->right = nullptr;
    size++;
    return node;
  }

  void track(int x)
  {
    if (size == 0)
    {
      root->key = x;
      root->value = 1;
      root->left = nullptr;
      root->right = nullptr;
      size++;
    }
    else
    {
      Node *runner = root;
      while (1)
      {
        if (x == runner->key)
        {
          runner->value++;
          break;
        }
        else if (x < runner->key)
        {
          if (runner->left == nullptr)
          {
            runner->left = createNode(x);
            break;
          }
          runner = runner->left;
        }
        else
        {
          if (runner->right == nullptr)
          {
            runner->right = createNode(x);
            break;
          }
          runner = runner->right;
        }
      }
    }
  }

  int getSumOfCount(Node *node, int th)
  {
    if (node == nullptr)
    {
      return 0;
    }
    else if (node->key >= th)
    {
      return getSumOfCount(node->left, th);
    }
    else if (node->key < th)
    {
      return node->value + getSumOfCount(node->left, th) + getSumOfCount(node->right, th);
    }
    else
    {
      return 0;
    }
  }

  int getRankOfNumber(int x)
  {
    Node *runner = root;
    while (runner != nullptr && runner->key > x)
    {
      runner = runner->left;
    }

    return getSumOfCount(runner, x);
  }
};

int main()
{
  int n, x;
  Rank rank;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    rank.track(x);
  }

  int m, ret;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    ret = rank.getRankOfNumber(x);
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
