#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 1000

// calculate length of the longest common subsequence
int calcLCS(string s1, string s2)
{
    int LCS[N + 1][N + 1];
    int m = s1.size();
    int n = s2.size();
    int maxLen = 0;
    s1 = " " + s1;
    s2 = " " + s2;

    // initialization
    for (int i = 0; i <= m; i++)
        LCS[i][0] = 0;
    for (int j = 0; j <= n; j++)
        LCS[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            maxLen = max(maxLen, LCS[i][j]);
        }
    }
    return maxLen;
}

bool oneEditAway(string s1, string s2)
{
    if (abs((int)s1.size() - (int)s2.size()) > 2)
        return false;

    int lcsLen = calcLCS(s1, s2);
    if (s1.size() - lcsLen > 1 || s2.size() - lcsLen > 1)
        return false;

    return true;
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
