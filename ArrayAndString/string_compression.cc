#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

string compress(char A[], int n)
{
    char x[1];
    int num = 0;
    stringstream ss;
    int i = 0;
    while (i < n)
    {
        if (A[i] != *x)
        {
            if (num > 0)
            {
                ss << *x;
                ss << num;
            }
            *x = A[i];
            num = 1;
        }
        else
        {
            num++;
        }

        if (i == n - 1)
        {
            ss << *x;
            ss << num;
        }
        i++;
    }
    return ss.str();
}

int main()
{
    char Array[100000];
    int n;

    scanf("%d", &n);

    // prevent scanf() from reading white-space.
    (void)getchar();

    for (int i = 0; i < n; i++)
        scanf("%c", &Array[i]);

    string ret = compress(Array, n);

    if (ret.length() < n)
    {
        cout << ret << endl;
    }
    else
    {
        cout << Array << endl;
    }

    return 0;
}
