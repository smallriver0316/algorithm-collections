#include <iostream>
using namespace std;

#define N 100000

struct Card
{
    char suit;
    int num;
    int index;
};

int partition(Card A[], int p, int r)
{
    int x = A[r].num;
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j].num <= x)
            swap(A[++i], A[j]);
    }
    swap(A[++i], A[r]);

    return i;
}

void quickSort(Card A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

bool isStable(Card A[], int n)
{
    bool ans = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i].num == A[i + 1].num && A[i].index > A[i + 1].index)
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    Card A[N];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].suit >> A[i].num;
        A[i].index = i;
    }

    quickSort(A, 0, n - 1);

    if (isStable(A, n))
        cout << "Stable" << endl;
    else
        cout << "Not Stable" << endl;

    for (int i = 0; i < n; i++)
        cout << A[i].suit << " " << A[i].num << endl;

    return 0;
}
