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

  TreeNode *getIthNode(int i)
  {
    int leftSize = left == nullptr ? 0 : left->getSize();
    if (i < leftSize)
    {
      return left->getIthNode(i);
    }
    else if (i == leftSize)
    {
      return this;
    }
    else
    {
      return right->getIthNode(i - (leftSize + 1));
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

class Tree
{
  TreeNode *root = nullptr;

public:
  int size()
  {
    if (root == nullptr)
    {
      return 0;
    }
    else
    {
      return root->getSize();
    }
  }

  TreeNode *getRandomNode()
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand100(0, size() - 1);
    int index = rand100(mt);
    return root->getIthNode(index);
  }

  void insertInOrder(int d)
  {
    if (root == nullptr)
    {
      root = new TreeNode(d);
    }
    else
    {
      root->insertInOrder(d);
    }
  }

  TreeNode *findNode(int d)
  {
    if (root == nullptr)
    {
      return nullptr;
    }
    else
    {
      return root->findNode(d);
    }
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
  Tree T;

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
        T.insertInOrder(num);
      }
      else if (regex_match(com, re_search))
      {
        scanf("%d", &num);
        TreeNode *ret = T.findNode(num);
        printNode(ret);
      }
      else if (regex_match(com, re_random))
      {
        TreeNode *ret = T.getRandomNode();
        printNode(ret);
      }
      else
      {
        cout << "[ERROR] Command is invalid" << endl;
        return -1;
      }
    }
  }
  catch (const exception &e)
  {
    cerr << e.what() << '\n';
  }

  return 0;
}
