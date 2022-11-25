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

int main()
{
  int n, x;
  /*
    s: stack which has sorted items
    t: stack to be used to evacuate items when sorting
  */
  Stack s, t;

  cin >> n;

  // input
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    if (s.isEmpty() || x < s.peek())
    {
      s.push(x);
    }
    else
    {
      while (!s.isEmpty() && x > s.peek())
      {
        t.push(s.pop());
      }
      s.push(x);
      while (!t.isEmpty())
      {
        s.push(t.pop());
      }
    }
  }

  // output
  while (!s.isEmpty())
  {
    cout << s.pop() << " ";
  }
  cout << endl;

  return 0;
}
