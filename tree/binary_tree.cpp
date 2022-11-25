#include <iostream>
using namespace std;

#define MAX 100000
#define NIL -1

/*
    p: parent
    l: left child
    r: right child
*/
struct Node
{
    int p, l, r;
};

/*
    T: Tree
    D: depth of nodes
    H: height of nodes
*/
Node T[MAX];
int D[MAX], H[MAX];

void setDepth(int id, int d)
{
    if (id == NIL)
        return;
    D[id] = d;
    setDepth(T[id].l, d + 1);
    setDepth(T[id].r, d + 1);
}

int setHeight(int id)
{
    int h1 = 0, h2 = 0;
    if (T[id].l != NIL)
    {
        h1 = setHeight(T[id].l) + 1;
    }
    if (T[id].r != NIL)
    {
        h2 = setHeight(T[id].r) + 1;
    }
    return H[id] = h1 > h2 ? h1 : h2;
}

int getSibling(int id)
{
    if (T[id].p == NIL)
        return NIL;
    if (T[T[id].p].r != id && T[T[id].p].l != NIL)
    {
        return T[T[id].p].l;
    }
    if (T[T[id].p].l != id && T[T[id].p].r != NIL)
    {
        return T[T[id].p].r;
    }
    return NIL;
}

void printNode(int id)
{
    cout << "node " << id << ": ";
    cout << "parent = " << T[id].p << ", ";
    cout << "sibling = " << getSibling(id) << ", ";
    int degree = 0;
    if (T[id].l != NIL && T[id].r != NIL)
    {
        degree = 2;
    }
    else if (T[id].l != NIL || T[id].r != NIL)
    {
        degree = 1;
    }
    cout << "degree = " << degree << ", ";
    cout << "depth = " << D[id] << ", ";
    cout << "height = " << H[id] << ", ";
    if (T[id].p == NIL)
        cout << "root" << endl;
    else if (T[id].l != NIL || T[id].r != NIL)
        cout << "internal node" << endl;
    else
        cout << "leaf" << endl;
}

int main()
{
    int n, id, l, r, root;

    cin >> n;

    // initialization
    for (int i = 0; i < n; i++)
    {
        T[i].p = T[i].l = T[i].r = NIL;
    }

    // input tree
    for (int i = 0; i < n; i++)
    {
        cin >> id >> l >> r;
        T[id].l = l;
        T[id].r = r;
        if (l != NIL)
            T[l].p = id;
        if (r != NIL)
            T[r].p = id;
    }

    // search root
    for (int i = 0; i < n; i++)
    {
        if (T[id].p == NIL)
        {
            root = i;
            break;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < n; i++)
    {
        printNode(i);
    }

    return 0;
}
