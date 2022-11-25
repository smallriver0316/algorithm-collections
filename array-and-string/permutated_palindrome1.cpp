#include <iostream>
#include <string>
#include <ctype.h>
#include <cctype>
using namespace std;

// ASCII code has 128 characters
#define N 128

bool isPermutatedPalindrome(string s)
{
    int hist[N];
    for (int i = 0; i < N; i++)
        hist[i] = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isspace(s[i]))
            hist[tolower(s[i])]++;
    }

    int oddCount = 0;
    for (int i = 0; i < N; i++)
    {
        if (hist[i] > 0 && hist[i] % 2 == 1)
            oddCount++;

        if (oddCount > 1)
            break;
    }

    if (oddCount > 1)
        return false;
    else
        return true;
}

int main()
{
    string s;
    getline(cin, s);

    if (isPermutatedPalindrome(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
