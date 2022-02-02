#include <iostream>
#include <string>
using namespace std;

#define N 5

class Stack
{
  int top, S[N];

public:
  Stack()
  {
    top = 0;
  }

  bool isFull()
  {
    if (top == N)
    {
      return true;
    }
    return false;
  }

  bool isEmpty()
  {
    if (top == 0)
    {
      return true;
    }
    return false;
  }

  void push(int x)
  {
    if (isFull())
    {
      cout << "[ERROR] Stack is full" << endl;
      throw "[ERROR] Stack is full";
    }
    S[top++] = x;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Stack is empty" << endl;
      throw "[ERROR] Stack is empty";
    }
    return S[--top];
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Stack is empty" << endl;
      throw "[ERROR] Stack is empty";
    }
    return S[top - 1];
  }
};

struct Node
{
  Stack stack;
  Node *next;
};

class SetOfStacks
{
  Node *top;

public:
  SetOfStacks()
  {
    top = (Node *)malloc(sizeof(Node));
    top->next = nullptr;
  }

  bool isEmpty()
  {
    if (top == nullptr)
    {
      return true;
    }
    else if (top->next == nullptr)
    {
      return top->stack.isEmpty();
    }
    else
    {
      return false;
    }
  }

  void push(int x)
  {
    if (top->stack.isFull())
    {
      Node *node = (Node *)malloc(sizeof(Node));
      node->stack.push(x);
      node->next = top;
      top = node;
    }
    else
    {
      top->stack.push(x);
    }
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Set of stack is empty" << endl;
      throw "[ERROR] Set of stack is empty";
    }
    if (top->stack.isEmpty())
    {
      Node *tmp = top;
      top = top->next;
      free(tmp);
    }
    return top->stack.pop();
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Set of stack is empty" << endl;
      throw "[ERROR] Set of stack is empty";
    }
    if (top->stack.isEmpty())
    {
      top = top->next;
    }
    return top->stack.peek();
  }
};

int main()
{
  int n, v;
  SetOfStacks stack;

  try
  {
    // input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> v;
      stack.push(v);
    }

    // output
    for (int i = 0; i < n; i++)
    {
      cout << stack.pop() << " ";
    }
    cout << endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
