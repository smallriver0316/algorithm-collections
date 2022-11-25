#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <unordered_map>
using namespace std;

bool isPermutatedPalindrome(string s)
{
    unordered_map<char, int> hist;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isspace(s[i]))
            hist[tolower(s[i])]++;
    }

    int oddCount = 0;
    for (auto itr = hist.begin(); itr != hist.end(); ++itr)
    {
        if (itr->second % 2 == 1)
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
