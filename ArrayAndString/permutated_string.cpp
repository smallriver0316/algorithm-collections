#include <iostream>
#include <string>
using namespace std;

// ASCII code has 128 characters
#define N 128

bool isPermutated(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    int hist[N];
    for (int i = 0; i < N; i++)
        hist[i] = 0;

    for (int i = 0; i < s1.size(); i++)
        hist[s1[i]]++;

    for (int i = 0; i < s2.size(); i++)
    {
        if (hist[s2[i]] > 0)
            hist[s2[i]]--;
        else
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    if (isPermutated(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
