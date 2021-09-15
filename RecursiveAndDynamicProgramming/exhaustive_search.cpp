#include <iostream>
using namespace std;

#define MAX 20

int n, A[MAX];

// Bubble Sort
void sortAscend()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

/*
    index: index of Array
    m: target value
*/
bool exhaustiveSearch(int index, int m)
{
    if (index >= n)
        return false;
    if (A[index] == m)
        return true;
    else if (A[index] < m)
    {
        return exhaustiveSearch(index + 1, m - A[index]) || exhaustiveSearch(index + 1, m);
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sortAscend();

    int q, m;
    bool ret;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        ret = exhaustiveSearch(0, m);
        if (ret)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
