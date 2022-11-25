#include <iostream>
using namespace std;

#define MAX 25
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

Node T[MAX];

int findRoot(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (T[i].p == NIL)
            break;
    }
    return i;
}

// 先行順巡回
// node->left->right
void preorderWalk(int root)
{
    int left = T[root].l;
    int right = T[root].r;

    cout << root << " ";

    if (left != NIL)
        preorderWalk(left);

    if (right != NIL)
        preorderWalk(right);
}

// 中間順巡回
// left->node->right
void inorderWalk(int root)
{
    int left = T[root].l;
    int right = T[root].r;

    if (left != NIL)
        inorderWalk(left);

    cout << root << " ";

    if (right != NIL)
        inorderWalk(right);
}

// 後行順巡回
// left->right->node
void postorderWalk(int root)
{
    int left = T[root].l;
    int right = T[root].r;

    if (left != NIL)
        postorderWalk(left);

    if (right != NIL)
        postorderWalk(right);

    cout << root << " ";
}

int main()
{
    int n, id, l, r;

    cin >> n;

    // initializaton
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
        {
            T[l].p = id;
        }
        if (r != NIL)
        {
            T[r].p = id;
        }
    }

    int root = findRoot(n);

    cout << "Preorder" << endl;
    preorderWalk(root);
    cout << endl;

    cout << "Inorder" << endl;
    inorderWalk(root);
    cout << endl;

    cout << "Postorder" << endl;
    postorderWalk(root);
    cout << endl;

    return 0;
}
