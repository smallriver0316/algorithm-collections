#include <iostream>
#include <string>
using namespace std;

#define N 100

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

void sortStack(Stack *stack)
{
  int tmp;
  Stack buf;

  while (!stack->isEmpty())
  {
    tmp = stack->pop();
    if (buf.isEmpty() || tmp >= buf.peek())
    {
      buf.push(tmp);
    }
    else
    {
      while (!buf.isEmpty() && tmp <= buf.peek())
      {
        stack->push(buf.pop());
      }
      buf.push(tmp);
    }
  }

  while (!buf.isEmpty())
  {
    stack->push(buf.pop());
  }
}

int main()
{
  int n, x;
  Stack stack;

  cin >> n;

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (!stack.isFull())
    {
      stack.push(x);
    }
  }

  sortStack(&stack);

  // output
  while (!stack.isEmpty())
  {
    cout << stack.pop() << " ";
  }
  cout << endl;

  return 0;
}
