#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

int main()
{
    int n, key;
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

    int target;
    cin >> target;

    Node *pt1 = nil->next;
    Node *pt2 = nil;
    while (pt1 != nil)
    {
        if (pt1->key == target)
        {
            pt2->next = pt1->next;
            free(pt1);
            // when delete pt1, it doesn't proceed pt2, because the node next to deleted node may be deleting target
            pt1 = pt2->next;
        }
        else
        {
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
    }

    // output
    cur = nil->next;
    while (cur != nil)
    {
        cout << cur->key << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
