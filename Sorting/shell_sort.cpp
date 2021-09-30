#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

#define N 1000000

long long cnt = 0;
int n, A[N];
vector<int> G;

void insertionSort(int g)
{
    for (int i = g; i < n; i++)
    {
        int target = A[i];
        int j = i - g;
        for (; j >= 0, A[j] > target; j -= g)
        {
            A[j + g] = A[j];
            cnt++;
        }
        A[j + g] = target;
    }
}

void shellSort()
{
    /*
        Gap sequece of shell sort must have 1 in order to sort completely.
        It is said that using sequence of g(n + 1) = 3 * g(n) + 1 enables to sort within O(N1.25).
    */
    for (int h = 1; h < n; h = 3 * h + 1)
    {
        G.push_back(h);
    }
    for (int i = G.size() - 1; i >= 0; i--)
    {
        insertionSort(G[i]);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    shellSort();

    // output

    // size of G
    cout << G.size() << endl;
    // elements of G
    for (int i = 0; i < G.size(); i++)
    {
        if (i == 0)
            cout << G[i];
        else
            cout << " " << G[i];
    }
    cout << endl;
    // number of replacements
    cout << cnt << endl;
    // sorted array
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << A[i];
        else
            cout << " " << A[i];
    }
    cout << endl;

    return 0;
}
