#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    Node *prev, *next;
};

int main()
{
    int n, key;
    unordered_map<int, int> map;
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
        // insert to end of list
        x->prev = nil->prev;
        nil->prev->next = x;
        nil->prev = x;
        x->next = nil;
    }

    // make unique
    Node *cur = nil->next;
    while (cur != nil)
    {
        Node *next = cur->next;
        if (map[cur->key] > 0)
        {
            // delete node
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
        }
        else
        {
            map[cur->key]++;
        }
        cur = next;
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
