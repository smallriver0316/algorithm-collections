#include <iostream>
#include <string>
#include <ctype.h>
#include <cctype>
using namespace std;

bool isPermutatedPalindrome(string s)
{
    int bitVector = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isspace(s[i]))
        {
            char a = 'a';
            int index = (int)tolower(s[i]) - (int)a;
            if (index < 0)
                break;
            int mask = 1 << index;
            if ((bitVector & mask) == 0)
            {
                bitVector |= mask;
            }
            else
            {
                bitVector &= ~mask;
            }
        }
    }
    return bitVector == 0 || (bitVector & (bitVector - 1)) == 0;
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
