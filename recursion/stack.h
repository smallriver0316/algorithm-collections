#include <iostream>
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
      cout << "[ERROR] Stack is full!" << endl;
      throw "[ERROR] Stack is full";
    }
    S[top++] = x;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Stack is empty!" << endl;
      throw "[ERROR] Stack is empty!";
    }
    return S[--top];
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "[ERROR] Stack is empty!" << endl;
      throw "[ERROR] Stack is empty!";
    }
    return S[top - 1];
  }
};
