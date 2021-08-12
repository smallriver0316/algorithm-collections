#include <iostream>
using namespace std;
#define MAX 100000
#define NIL -1

// left-child, right-sibling representation
struct Node
{
    int p, l, r;
};

/*
    T: Tree
    D: depth of nodes
    n: number of nodes
*/
Node T[MAX];
int D[MAX];

void printNode(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if (T[u].p == NIL)
    {
        cout << "root, ";
    }
    else if (T[u].l == NIL)
    {
        cout << "leaf, ";
    }
    else
    {
        cout << "internal node, ";
    }

    cout << "[";
    for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << c;
    }
    cout << "]" << endl;
}

void setDepth(int id, int d)
{
    // set depth of self
    D[id] = d;
    // set depth of sibling
    if (T[id].r != NIL)
    {
        setDepth(T[id].r, d);
    }
    // set depth of child
    if (T[id].l != NIL)
    {
        setDepth(T[id].l, d + 1);
    }
}

int main()
{
    int n, id, k, c, left, right;

    cin >> n;

    // initialization
    for (int i = 0; i < n; i++)
    {
        T[i].p = T[i].l = T[i].r = NIL;
    }

    // input tree
    for (int i = 0; i < n; i++)
    {
        cin >> id >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            if (j == 0)
            {
                T[id].l = c;
            }
            else
            {
                T[left].r = c;
            }
            left = c;
            T[c].p = id;
        }
    }

    // search root
    for (int i = 0; i < n; i++)
    {
        if (T[i].p == NIL)
            right = i;
    }

    // set depth
    setDepth(right, 0);

    for (int i = 0; i < n; i++)
        printNode(i);

    return 0;
}
