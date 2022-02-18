#include <iostream>
#include <vector>
using namespace std;

#define N 1000
#define NIL -1

struct Node
{
  int key, p, l, r;
};

struct LinkNode
{
  Node value;
  LinkNode *next;
};

Node T[N];
vector<LinkNode *> D;

void createDepthLinkedList(int index, int depth)
{
  if (index == NIL)
  {
    return;
  }

  Node x = T[index];
  if (D.size() < depth + 1)
  {
    LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
    head->value = x;
    head->next = nullptr;
    D.push_back(head);
  }
  else
  {
    LinkNode *tail = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *runner = D[depth];
    while (runner->next != nullptr)
    {
      runner = runner->next;
    }
    tail->value = x;
    tail->next = runner->next;
    runner->next = tail;
  }

  createDepthLinkedList(x.l, depth + 1);
  createDepthLinkedList(x.r, depth + 1);
}

int main()
{
  int n, key, l, r;

  cin >> n;

  // initialization
  for (int i = 0; i < n; i++)
  {
    T[i].p = T[i].l = T[i].r = NIL;
  }

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> key >> l >> r;
    T[i].key = key;
    T[i].l = l;
    T[i].r = r;
    if (l != NIL)
    {
      T[l].p = i;
    }
    if (r != NIL)
    {
      T[r].p = i;
    }
  }

  // find root
  int rootIndex;
  for (int i = 0; i < n; i++)
  {
    if (T[i].p == NIL)
    {
      rootIndex = i;
      break;
    }
  }

  createDepthLinkedList(rootIndex, 0);

  // output
  for (int i = 0; i < D.size(); i++)
  {
    LinkNode *runner = D[i];
    cout << "depth" << i << ": ";
    while (runner != nullptr)
    {
      cout << runner->value.key << " ";
      runner = runner->next;
    }
    cout << endl;
  }

  return 0;
}
