#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <regex>
using namespace std;

struct Node
{
    int key;
    Node *prev, *next;
};

class DoubleLinkedList
{
    Node *nil;

public:
    DoubleLinkedList()
    {
        nil = (Node *)malloc(sizeof(Node));
        nil->prev = nil;
        nil->next = nil;
    }

    void insert(int key)
    {
        Node *x = (Node *)malloc(sizeof(Node));
        x->key = key;
        x->next = nil->next;
        nil->next->prev = x;
        nil->next = x;
        x->prev = nil;
    }

    Node *search(int key)
    {
        Node *cur = nil->next;
        while (cur != nil && cur->key != key)
        {
            cur = cur->next;
        }
        return cur;
    }

    void deleteNode(int key)
    {
        Node *x = search(key);
        if (x == nil)
            return;
        x->prev->next = x->next;
        x->next->prev = x->prev;
        free(x);
    }

    void deleteFisrt()
    {
        Node *top = nil->next;
        top->prev->next = top->next;
        top->next->prev = top->prev;
        free(top);
    }

    void deleteLast()
    {
        Node *end = nil->prev;
        end->prev->next = end->next;
        end->next->prev = end->prev;
        free(end);
    }

    void show()
    {
        Node *cur = nil->next;
        while (cur != nil)
        {
            cout << cur->key << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    int key, n;
    char com[20];
    DoubleLinkedList dllist;

    scanf("%d", &n);
    // prevent scanf() from reading white-space.
    (void)getchar();

    regex re_insert("insert");
    regex re_delete("delete");
    regex re_delete_first("deleteFirst");
    regex re_delete_last("deleteLast");

    for (int i = 0; i < n; i++)
    {
        scanf("%s", com);
        if (regex_match(com, re_insert))
        {
            scanf("%d", &key);
            dllist.insert(key);
        }
        else if (regex_match(com, re_delete_first))
        {
            dllist.deleteFisrt();
        }
        else if (regex_match(com, re_delete_last))
        {
            dllist.deleteLast();
        }
        else if (regex_match(com, re_delete))
        {
            scanf("%d", &key);
            dllist.deleteNode(key);
        }
        else
        {
            return -1;
        }
        // prevent scanf() from reading white-space.
        (void)getchar();
    }
    dllist.show();
    return 0;
}
