#include <iostream>
#include <string>
using namespace std;

#define N 15
#define DEFAULT_SIZE 5
#define MAX_STACK_NUM 3

class StackInfo
{
  int adjustIndex(int index)
  {
    return ((index % N) + N) % N;
  }

public:
  /*
    start: start position of array allocated to each stack
    size: size actually used in stack
    capacity: the maximum size of stack
  */
  int start, size, capacity;

  StackInfo(int startPos, int capacitySize)
  {
    start = startPos;
    size = 0;
    capacity = capacitySize;
  }

  bool isWithinStackCapacity(int index)
  {
    if (index < 0 || index >= N)
    {
      return false;
    }
    /*
      As a matter of convenience, ignore the size of provided array here,
      handling the stack area as a straight one array.
    */
    int contiguousIndex = index < start ? N + index : index;
    int end = start + capacity;
    return start <= contiguousIndex && contiguousIndex < end;
  }

  bool isFull()
  {
    return size == capacity;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  int lastCapacityIndex()
  {
    return adjustIndex(start + capacity - 1);
  }

  int lastElementIndex()
  {
    return adjustIndex(start + size - 1);
  }
};

class VariableMultiStack
{
  StackInfo *info = (StackInfo *)malloc(sizeof(StackInfo) * MAX_STACK_NUM);
  int values[N];
  int numOfStack;

  int adjustIndex(int index)
  {
    /*
      1. (index % N) calculates surplus against array (if index is more than array size).
      2. Adding array size to step 1 assumes specified position on virtual array of double size.
      3. Moreover, calculating surplus of step 2 leads the position of actual array.
    */
    return ((index % N) + N) % N;
  }

  int nextIndex(int index)
  {
    return adjustIndex(index + 1);
  }

  int previousIndex(int index)
  {
    return adjustIndex(index - 1);
  }

  void shift(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }

    // if the current stack is full, shift next stack
    if (info[stackIndex].size >= info[stackIndex].capacity)
    {
      int nextStackIndex = (stackIndex + 1) % numOfStack;
      shift(nextStackIndex);
      info[stackIndex].capacity++;
    }

    int index = info[stackIndex].lastCapacityIndex();
    while (info[stackIndex].isWithinStackCapacity(index))
    {
      values[index] = values[previousIndex(index)];
      index = previousIndex(index);
    }

    values[info[stackIndex].start] = 0;
    info[stackIndex].start = nextIndex(info[stackIndex].start);
    info[stackIndex].capacity--;
  }

  void expand(int stackIndex)
  {
    shift((stackIndex + 1) % numOfStack);
    info[stackIndex].capacity++;
  }

public:
  VariableMultiStack(int stackNum, int stackSize)
  {
    if (stackNum > MAX_STACK_NUM)
    {
      throw "[ERROR] Exceed maximum stack size";
    }
    if (stackNum * stackSize > N)
    {
      throw "[ERROR] Exceed total capacity";
    }

    numOfStack = stackNum;

    for (int i = 0; i < stackNum; i++)
    {
      info[i] = StackInfo(i * stackSize, stackSize);
    }
  }

  int numOfElements()
  {
    int sum = 0;
    for (int i = 0; i < numOfStack; i++)
    {
      sum += info[i].size;
    }
    return sum;
  }

  bool allStacksAreFull()
  {
    return numOfElements() == N;
  }

  void push(int stackIndex, int value)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }
    if (allStacksAreFull())
    {
      throw "[ERROR] There is no space to push item";
    }

    if (info[stackIndex].isFull())
    {
      expand(stackIndex);
    }

    info[stackIndex].size++;
    values[info[stackIndex].lastElementIndex()] = value;
  }

  int pop(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }

    if (info[stackIndex].isEmpty())
    {
      throw "[ERROR] Stack is empty";
    }

    int value = values[info[stackIndex].lastElementIndex()];
    values[info[stackIndex].lastElementIndex()] = 0;
    info[stackIndex].size--;
    return value;
  }

  int peek(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }
    if (info[stackIndex].isEmpty())
    {
      throw "[ERROR] Stack is empty";
    }

    return values[info[stackIndex].lastElementIndex()];
  }

  bool isEmpty(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }
    return info[stackIndex].isEmpty();
  }

  bool isFull(int stackIndex)
  {
    if (stackIndex >= numOfStack)
    {
      throw "[ERROR] Stack Index is out of range";
    }
    return info[stackIndex].isFull();
  }
};

int main()
{
  int n, k, v;
  VariableMultiStack stack(3, 5);

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
    std::cerr << e.what() << "\n";
  }

  return 0;
}
