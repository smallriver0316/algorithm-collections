#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// s1 is shorter than s2
bool oneEditInsert(string s1, string s2)
{
    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] != s2[j])
        {
            if (i != j)
                return false;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return true;
}

// the length of two string are same.
bool oneEditReplace(string s1, string s2)
{
    int diff = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            diff++;
        if (diff >= 2)
            return false;
    }
    return true;
}

bool oneEditAway(string s1, string s2)
{
    if (s1.size() == s2.size())
        return oneEditReplace(s1, s2);
    else if (s1.size() + 1 == s2.size())
        return oneEditInsert(s1, s2);
    else if (s1.size() - 1 == s2.size())
        return oneEditInsert(s2, s1);
    else
        return false;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (oneEditAway(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
