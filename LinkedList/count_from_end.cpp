#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

int main()
{
    int n, k, key;
    Node *nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;

    cin >> n;
    Node *cur = nil;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        Node *x = (Node *)malloc(sizeof(Node));
        x->key = key;
        cur->next = x;
        x->next = nil;
        cur = cur->next;
    }

    cin >> k;
    if (n < k)
    {
        cout << "[ERROR] k must be less than n" << endl;
        return 1;
    }

    Node *pt1 = nil->next;
    Node *pt2 = nil->next;
    for (int i = 0; i < k; i++)
    {
        pt2 = pt2->next;
    }
    while (pt2 != nil)
    {
        pt1 = pt1->next;
        pt2 = pt2->next;
    }
    cout << pt1->key << endl;

    return 0;
}
