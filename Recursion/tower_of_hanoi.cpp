#include <iostream>
#include "stack.h"
using namespace std;

void moveDisks(int num, int org, int dst, int tmp, Stack *stacks)
{
  if (num <= 0)
  {
    return;
  }
  else if (num == 1)
  {
    int disk = stacks[org].pop();
    stacks[dst].push(disk);
  }
  else
  {
    moveDisks(num - 1, org, tmp, dst, stacks);
    moveDisks(1, org, dst, tmp, stacks);
    moveDisks(num - 1, tmp, dst, org, stacks);
  }
}

int main()
{
  int n;
  Stack s1, s2, s3;
  Stack stacks[] = {s1, s2, s3};

  cin >> n;

  if (n > 100)
  {
    cout << "[ERROR] The number of disks must be less than 100!" << endl;
    return -1;
  }

  for (int i = n - 1; i >= 0; i--)
  {
    stacks[0].push(i);
  }

  moveDisks(n, 0, 2, 1, stacks);

  for (int i = 0; i < n; i++)
  {
    cout << stacks[2].pop() << ", ";
  }
  cout << endl;

  return 0;
}
