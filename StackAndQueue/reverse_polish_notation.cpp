#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int top, S[200];

public:
    Stack()
    {
        top = 0;
    }

    void push(int x)
    {
        S[++top] = x;
    }

    int pop()
    {
        top--;
        int x = S[top + 1];
        return x;
    }

    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 199)
            return true;
        else
            return false;
    }
};

int main()
{
    int a, b, c;
    char s[100];
    Stack stack;

    while (1)
    {
        if (scanf("%s", s) == 1)
        {
            if (s[0] == '+')
            {
                a = stack.pop();
                b = stack.pop();
                stack.push(a + b);
            }
            else if (s[0] == '-')
            {
                a = stack.pop();
                b = stack.pop();
                stack.push(b - a);
            }
            else if (s[0] == '*')
            {
                a = stack.pop();
                b = stack.pop();
                stack.push(a * b);
            }
            else
            {
                stack.push(atoi(s));
            }
        }

        // distinguish EOF
        c = getchar();
        if (c == '\n' || c == '\0')
        {
            break;
        }
    }

    printf("%d\n", stack.pop());
    return 0;
}
