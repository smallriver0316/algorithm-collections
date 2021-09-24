#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define N 1000

// calculate length of the longest common subsequence
int calcLCS(string X, string Y)
{
    int LCS[N + 1][N + 1];
    int m = X.size();
    int n = Y.size();
    int maxlen = 0;
    X = " " + X;
    Y = " " + Y;

    // initialization
    // first elements are pseudo ones, so make them zeros.
    for (int i = 0; i <= m; i++)
        LCS[i][0] = 0;
    for (int j = 0; j <= n; j++)
        LCS[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
            maxlen = max(maxlen, LCS[i][j]);
        }
    }
    return maxlen;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << calcLCS(s1, s2) << endl;
    return 0;
}
