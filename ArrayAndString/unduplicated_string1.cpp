#include <iostream>
#include <string>
using namespace std;

// ASCII code has 128 characters.
#define N 128

bool isUniqueChars(string s)
{
    if (s.size() > N)
        return false;

    bool char_set[N];
    for (int i = 0; i < N; i++)
        char_set[i] = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (char_set[s[i]])
            return false;

        char_set[s[i]] = true;
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
