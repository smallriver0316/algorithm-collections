#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <regex>
using namespace std;

struct Node
{
  int key;
  Node *p, *l, *r;
};

class BinaryTree
{
  Node *head;
  int size;

public:
  BinaryTree()
  {
    head = nullptr;
    size = 0;
  }

  void insertNode(int key)
  {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    if (head == nullptr)
    {
      node->p = node->l = node->r = nullptr;
      head = node;
    }
    else
    {
      Node *walker = head;
      while (walker != nullptr)
      {
        if (node->key < walker->key)
        {
          if (walker->l == nullptr)
          {
            node->p = walker;
            node->l = node->r = nullptr;
            walker->l = node;
            break;
          }
          walker = walker->l;
        }
        else
        {
          if (walker->r == nullptr)
          {
            node->p = walker;
            node->l = node->r = nullptr;
            walker->r = node;
            break;
          }
          walker = walker->r;
        }
      }
    }
    size++;
  }

  Node *searchNode(int key)
  {
    Node *walker = head;
    while (walker != nullptr)
    {
      if (key == walker->key)
      {
        return walker;
      }
      else if (key < walker->key)
      {
        walker = walker->l;
      }
      else
      {
        walker = walker->r;
      }
    }
    return nullptr;
  }

  void deleteNode(int key)
  {
    Node *walker = head;
    while (walker != nullptr)
    {
      if (key < walker->key)
      {
        walker = walker->l;
      }
      else if (key > walker->key)
      {
        walker = walker->r;
      }
      else // key == walker->key
      {
        if (walker->l == nullptr && walker->r == nullptr)
        {
          if (walker->p != nullptr)
          {
            if (walker->p->l == walker)
            {
              walker->p->l = nullptr;
            }
            else
            {
              walker->p->r = nullptr;
            }
          }
          free(walker);
        }
        else if (walker->l != nullptr && walker->r == nullptr)
        {
          walker->l->p = walker->p;
          if (walker->p != nullptr)
          {
            if (walker->p->l == walker)
            {
              walker->p->l = walker->l;
            }
            else
            {
              walker->p->r = walker->l;
            }
          }
          free(walker);
        }
        else if (walker->l == nullptr && walker->r != nullptr)
        {
          walker->r->p = walker->p;
          if (walker->p != nullptr)
          {
            if (walker->p->l == walker)
            {
              walker->p->l = walker->r;
            }
            else
            {
              walker->p->r = walker->r;
            }
          }
          free(walker);
        }
        else // walker->l != nullptr && walker->r != nullptr
        {
          Node *alt = walker->r;
          while (alt->l != nullptr)
          {
            alt = alt->l;
          }
          if (alt->p != nullptr)
          {
            alt->p->l = alt->l;
          }
          alt->p = walker->p;
          alt->l = walker->l;
          alt->r = walker->r;
          free(walker);
        }
        size--;
        break;
      }
    }
  }

  Node *getRandomNode()
  {
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand100(0, size - 1);

    int num = rand100(mt);
    int *count = (int *)malloc(sizeof(int));
    *count = 0;
    Node *walker = head;
    vector<Node *> nodes;
    inorderWalk(walker, nodes);

    return nodes[num];
  }

  void inorderWalk(Node *node, vector<Node *> &arr)
  {
    if (node->l != nullptr)
    {
      inorderWalk(node->l, arr);
    }

    if (node != nullptr)
    {
      arr.push_back(node);
    }

    if (node->r != nullptr)
    {
      inorderWalk(node->r, arr);
    }
  }
};

void printNode(Node *node)
{
  cout << "Node: " << node->key;
  if (node->p != nullptr)
  {
    cout << ", parent: " << node->p->key;
  }
  else
  {
    cout << ", parent: null";
  }
  if (node->l != nullptr)
  {
    cout << ", left child: " << node->l->key;
  }
  else
  {
    cout << ", left child: null";
  }
  if (node->r != nullptr)
  {
    cout << ", right child: " << node->r->key;
  }
  else
  {
    cout << ", right child: null";
  }
  cout << endl;
}

int main()
{
  int n, num;
  char com[6];
  BinaryTree BT;

  try
  {
    regex re_insert("insert");
    regex re_delete("delete");
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
        BT.insertNode(num);
      }
      else if (regex_match(com, re_delete))
      {
        scanf("%d", &num);
        BT.deleteNode(num);
      }
      else if (regex_match(com, re_search))
      {
        scanf("%d", &num);
        Node *ret = BT.searchNode(num);
        if (ret != nullptr)
        {
          printNode(ret);
        }
        else
        {
          cout << "No such node" << endl;
        }
      }
      else if (regex_match(com, re_random))
      {
        Node *ret = BT.getRandomNode();
        printNode(ret);
      }
      else
      {
        cout << "[ERROR] Command is invalid." << endl;
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
