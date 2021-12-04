#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int compressLength(char A[], int n)
{
    char x[1];
    int length = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != *x)
        {
            if (count > 0)
            {
                // add length of one character and number of sequence: 1 + (log10(count) + 1)
                // log10(count) + 1 is number of digit.
                length += log10(count) + 2;
            }
            *x = A[i];
            count = 1;
        }
        else
        {
            count++;
        }

        if (i == n - 1)
        {
            length += log10(count) + 2;
        }
    }
    return length;
}

string compress(char A[], int n)
{
    char x[1];
    int num = 0;
    stringstream ss;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != *x)
        {
            if (num > 0)
            {
                ss << *x << num;
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
            ss << *x << num;
        }
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

    int finalLength = compressLength(Array, n);
    if (finalLength >= n)
    {
        cout << Array << endl;
    }
    else
    {
        string ret = compress(Array, n);
        cout << ret << endl;
    }

    return 0;
}
