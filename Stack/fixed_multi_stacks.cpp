#include <iostream>
#include <string>
using namespace std;

#define N 100
#define MAX_STACK_NUM 3

class FixedMultiStack
{
  int numOfStack = MAX_STACK_NUM;
  int S[N * MAX_STACK_NUM];
  // top specifies index of the next stack position
  // For example, when index of the last stacked item is 5, top is 6.
  int top[MAX_STACK_NUM];

public:
  FixedMultiStack(int stackNum)
  {
    if (stackNum > MAX_STACK_NUM)
    {
      throw "[ERROR] Exceed maximum stack size";
    }
    numOfStack = stackNum;
    for (int i = 0; i < stackNum; i++)
    {
      top[i] = i * N;
    }
  }

  bool isFull(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] stack index is out of range";
    }
    if (top[stackIndex] == (stackIndex + 1) * N)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isEmpty(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] stack index is out of range";
    }
    if (top[stackIndex] == stackIndex * N)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void push(int stackIndex, int value)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] stack index is out of range";
    }
    if (isFull(stackIndex))
    {
      throw "[ERROR] Stack is full";
    }
    S[top[stackIndex]++] = value;
  }

  int pop(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] stack index is out of range";
    }
    if (isEmpty(stackIndex))
    {
      throw "[ERROR] Stack is empty";
    }
    return S[--top[stackIndex]];
  }

  int peek(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] stack index is out of range";
    }
    if (isEmpty(stackIndex))
    {
      throw "[ERROR] Stack is emtpy";
    }
    return S[top[stackIndex] - 1];
  }
};

int main()
{
  int n, k, v;
  FixedMultiStack stack(3);

  try
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> k >> v;
      stack.push(k, v);
    }

    for (int i = 0; i < 3; i++)
    {
      while (!stack.isEmpty(i))
      {
        cout << stack.pop(i) << " ";
      }
      cout << endl;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
