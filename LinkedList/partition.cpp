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

    // input
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

    int pvt; // pivot
    cin >> pvt;

    // make partition
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = head;
    Node *pt1 = nil->next;
    Node *pt2 = nil;
    while (pt1 != nil)
    {
        if (pt1->key < pvt)
        {
            // remove pt1 node from input linked list
            pt2->next = pt1->next;
            // add pt1 to output linked list
            tail->next = pt1;
            pt1->next = head;
            // update tail
            tail = pt1;
            // update pt1
            pt1 = pt2->next;
        }
        else
        {
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
    }
    // connect remained linked list to the end of output liked list
    tail->next = nil->next;
    pt2->next = head;

    // output
    cur = head->next;
    while (cur != head)
    {
        cout << cur->key << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
