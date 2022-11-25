#include <iostream>
#include <random>
#include <regex>
using namespace std;

class TreeNode
{
  int data;
  TreeNode *left, *right;
  int size;

public:
  TreeNode(int d)
  {
    data = d;
    size = 1;
    left = nullptr;
    right = nullptr;
  }

  int getSize()
  {
    return size;
  }

  int getData()
  {
    return data;
  }

  TreeNode *getLeft()
  {
    return left;
  }

  TreeNode *getRight()
  {
    return right;
  }

  TreeNode *getRandomNode()
  {
    int leftSize = left == nullptr ? 0 : left->getSize();
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand100(0, size - 1);
    int index = rand100(mt);
    if (index < leftSize)
    {
      return left->getRandomNode();
    }
    else if (index == leftSize)
    {
      return this;
    }
    else
    {
      return right->getRandomNode();
    }
  }

  void insertInOrder(int d)
  {
    if (d <= data)
    {
      if (left == nullptr)
      {
        left = new TreeNode(d);
      }
      else
      {
        left->insertInOrder(d);
      }
    }
    else
    {
      if (right == nullptr)
      {
        right = new TreeNode(d);
      }
      else
      {
        right->insertInOrder(d);
      }
    }
    size++;
  }

  TreeNode *findNode(int d)
  {
    if (d == data)
    {
      return this;
    }
    else if (d < data)
    {
      return left != nullptr ? left->findNode(d) : nullptr;
    }
    else if (d > data)
    {
      return right != nullptr ? right->findNode(d) : nullptr;
    }
    return nullptr;
  }
};

void printNode(TreeNode *node)
{
  if (node != nullptr)
  {
    cout << "Node: " << node->getData();
    if (node->getLeft() != nullptr)
    {
      cout << ", left child: " << node->getLeft()->getData();
    }
    else
    {
      cout << ", left child: null";
    }
    if (node->getRight() != nullptr)
    {
      cout << ", right child: " << node->getRight()->getData();
    }
    else
    {
      cout << ", right child: null";
    }
    cout << endl;
  }
  else
  {
    cout << "No such node" << endl;
  }
}

int main()
{
  int n, num;
  char com[6];
  TreeNode *root = nullptr;

  try
  {
    regex re_insert("insert");
    regex re_search("search");
    regex re_random("random");

    scanf("%d", &n);
    (void)getchar();

    for (int i = 0; i < n; i++)
    {
      scanf("%s", com);
      if (regex_match(com, re_insert))
      {
        scanf("%d", &num);
        if (root == nullptr)
        {
          root = new TreeNode(num);
        }
        else
        {
          root->insertInOrder(num);
        }
      }
      else if (regex_match(com, re_search))
      {
        scanf("%d", &num);
        TreeNode *ret = root->findNode(num);
        printNode(ret);
      }
      else if (regex_match(com, re_random))
      {
        TreeNode *ret = root->getRandomNode();
        printNode(ret);
      }
      else
      {
        cout << "[ERROR] Command is invalid" << endl;
        return -1;
      }
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
