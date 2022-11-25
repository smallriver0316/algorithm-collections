#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string replaceSpace(string s, int n)
{
    int spaceCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isspace(s[i]))
            spaceCount++;
    }

    int index = n + spaceCount * 2;
    if (n < s.size())
        s[n] = '\0';

    for (int i = n - 1; i > 0; i--)
    {
        if (isspace(s[i]))
        {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3;
        }
        else
        {
            s[index - 1] = s[i];
            index--;
        }
    }
    return s;
}

int main()
{
    string s;
    int n;

    getline(cin, s);
    cin >> n;

    cout << replaceSpace(s, n) << endl;

    return 0;
}
