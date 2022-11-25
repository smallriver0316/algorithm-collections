#include <iostream>
#include <string>
using namespace std;

#define N 100

class Stack
{
private:
  int top, S[N];

public:
  Stack()
  {
    top = 0;
  }

  bool isFull()
  {
    if (top >= N - 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isEmpty()
  {
    if (top == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  virtual void push(int x)
  {
    if (isFull())
    {
      throw "[ERROR] Stack is full";
    }
    S[top++] = x;
  }

  virtual int pop()
  {
    if (isEmpty())
    {
      throw "[ERROR] Stack is empty";
    }
    return S[--top];
  }

  int peek()
  {
    if (isEmpty())
    {
      throw "[ERROR] Stack is empty";
    }
    return S[top - 1];
  }
};

class StackWithMin : public Stack
{
  Stack minStack;

public:
  void push(int x) override
  {
    Stack::push(x);
    if (minStack.isEmpty())
    {
      minStack.push(x);
    }
    else
    {
      int min = minStack.peek();
      if (min >= x)
      {
        minStack.push(x);
      }
    }
  }

  int pop() override
  {
    int x = Stack::peek();
    int min = minStack.peek();
    if (x == min)
    {
      minStack.pop();
    }
    return Stack::pop();
  }

  int min()
  {
    return minStack.peek();
  }
};

int main()
{
  int n, x;
  StackWithMin stack;

  try
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      stack.push(x);
    }

    for (int i = 0; i < n; i++)
    {
      cout << stack.min() << endl;
      stack.pop();
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
