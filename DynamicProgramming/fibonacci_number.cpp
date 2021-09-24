#include <iostream>
using namespace std;

#define N 44

int memo[N];

int fibonacci(int num)
{
    if (num == 0 || num == 1)
        return memo[num] = 1;

    if (memo[num] != -1)
        return memo[num];

    int ans = fibonacci(num - 1) + fibonacci(num - 2);
    memo[num] = ans;
    return ans;
}

int main()
{
    int n, ret;
    cin >> n;

    // initialize MEMO array
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    ret = fibonacci(n);
    cout << ret << endl;

    return 0;
}
