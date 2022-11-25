#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *prev, *next;
};

int main()
{
    int n, key;
    Node *nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;

    // input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        Node *x = (Node *)malloc(sizeof(Node));
        x->key = key;
        x->prev = nil->prev;
        nil->prev->next = x;
        nil->prev = x;
        x->next = nil;
    }

    // make unique
    Node *cur = nil->next;
    while (cur != nil)
    {
        Node *runner = cur->next;
        while (runner != nil)
        {
            Node *next = runner->next;
            if (runner->key == cur->key)
            {
                // delete node
                runner->prev->next = runner->next;
                runner->next->prev = runner->prev;
                free(runner);
            }
            runner = next;
        }
        cur = cur->next;
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
