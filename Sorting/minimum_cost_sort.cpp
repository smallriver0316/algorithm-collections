#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000
#define MAX 10000

/*
    A: input array
    B: sorted array
    T: transition of index by sorting, key is index before sorted and value is index after sorted.
*/
int A[N], B[N], T[N];

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minIdx])
                minIdx = j;
        }
        swap(A[i], A[minIdx]);
        swap(T[i], T[minIdx]);
    }
}

int calcMinimumCost(int n, int minv)
{
    int ret = 0;
    bool V[n];
    // V is a list of flags whether checked or not
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
        T[i] = i;
        V[i] = false;
    }

    // use Selection Sort in order to create memo of transition of index by sorting
    selectionSort(B, n);

    for (int i = 0; i < n; i++)
    {
        if (V[i])
            continue;
        // cur is position moved along with a cycle
        int cur = i;
        // sum is sum of weight included a cycle
        int sum = 0;
        // m  is minimum value within a cycle
        int m = MAX;
        // cnt is num of elements within a cycle
        int cnt = 0;

        while (1)
        {
            // mark current position as checked
            V[cur] = true;
            cnt++;
            int v = A[cur];
            m = min(m, v);
            sum += v;
            cur = T[cur];
            if (V[cur])
                // if next position has already checked, finish cycle.
                break;
        }
        // select minimum value of using minimum value in a cycle or using minimum value in whole array.
        ret += min(sum + (cnt - 2) * m, m + sum + (cnt + 1) * minv);
    }
    return ret;
}

int main()
{
    int n;
    int minv = MAX;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        minv = min(minv, A[i]);
    }

    int ret = calcMinimumCost(n, minv);
    cout << ret << endl;

    return 0;
}
