#include <iostream>
#include <string>
#include <regex>
using namespace std;

#define N 10

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

class Queue
{
  Stack lifoStack, fifoStack;

public:
  void enqueue(int x)
  {
    if (!lifoStack.isEmpty())
    {
      while (!fifoStack.isFull() && !lifoStack.isEmpty())
      {
        fifoStack.push(lifoStack.pop());
      }
    }
    if (fifoStack.isFull())
    {
      cout << "[ERROR] Queue is full" << endl;
      throw "[ERROR] Queue is full";
    }
    fifoStack.push(x);
  }

  int dequeue()
  {
    if (!fifoStack.isEmpty())
    {
      while (!fifoStack.isEmpty() && !lifoStack.isFull())
      {
        lifoStack.push(fifoStack.pop());
      }
    }
    if (lifoStack.isEmpty())
    {
      cout << "[ERROR] Queue is empty" << endl;
      throw "[ERROR] Queue is empty";
    }
    return lifoStack.pop();
  }

  bool isEmpty()
  {
    return lifoStack.isEmpty() && fifoStack.isEmpty();
  }
};

int main()
{
  int n, num;
  char com[7];
  Queue queue;

  try
  {
    regex re_enqueue("enqueue");
    regex re_dequeue("dequeue");

    scanf("%d", &n);
    (void)getchar();

    for (int i = 0; i < n; i++)
    {
      scanf("%s", com);
      if (regex_match(com, re_enqueue))
      {
        scanf("%d", &num);
        queue.enqueue(num);
      }
      else if (regex_match(com, re_dequeue))
      {
        int x = queue.dequeue();
        cout << "dequeue: " << x << endl;
      }
      else
      {
        cout << "[ERROR] Provided command is invalid." << endl;
        return -1;
      }
    }

    while (!queue.isEmpty())
    {
      cout << queue.dequeue() << " ";
    }
    cout << endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
