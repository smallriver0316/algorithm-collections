#include <iostream>
using namespace std;

#define N 36

struct Card
{
    char suit;
    int value;
    int index;
};

void bubbleSort(Card A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j - 1].value > A[j].value)
            {
                swap(A[j - 1], A[j]);
            }
        }
    }
}

void selectionSort(Card A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (A[j].value < A[minj].value)
            {
                minj = j;
            }
        }
        swap(A[i], A[minj]);
    }
}

void printArray(Card A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

void isStable(Card A[], int n)
{
    bool ret = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i].value == A[i + 1].value && A[i].index > A[i + 1].index)
        {
            ret = false;
            break;
        }
    }

    if (ret)
        cout << "Stable" << endl;
    else
        cout << "Not Stable" << endl;
}

int main()
{
    int n, value;
    char suit;
    Card C1[N], C2[N];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> suit >> value;
        C1[i].suit = C2[i].suit = suit;
        C1[i].value = C2[i].value = value;
        C1[i].index = C2[i].index = i;
    }

    bubbleSort(C1, n);
    selectionSort(C2, n);

    printArray(C1, n);
    isStable(C1, n);
    printArray(C2, n);
    isStable(C2, n);

    return 0;
}
