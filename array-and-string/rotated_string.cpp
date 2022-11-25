#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2)
{
    size_t foundAt = s2.find(s1);

    if (foundAt >= 0 && foundAt < s2.size())
    {
        return true;
    }
    return false;
}

bool isRotatedString(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    string s3 = s2 + s2;
    return isSubstring(s1, s3);
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    if (isRotatedString(s1, s2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
