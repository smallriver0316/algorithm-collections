#include <iostream>
#include <string>
using namespace std;

// input string assumed to be composed of alphabets only
#define N 26

bool isUniqueChars(string s)
{
    if (s.size() > N)
        return false;

    int checker = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // character should be used with single quotation, double quotation is used for string
        char a = 'a';
        int val = (int)s[i] - (int)(a);
        if ((checker & (1 << val)) > 0)
            return false;
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    if (isUniqueChars(s))
        cout << "Unique" << endl;
    else
        cout << "Not Unique" << endl;

    return 0;
}
