#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

void addLinkedList(Node *list1, Node *list2) {
  Node *nil = (Node *)malloc(sizeof(Node));
  Node *runner1 = list1->next;
  Node *runner2 = list2->next;
  nil->next = nil;
  unsigned int carry = 0;

  Node *cur = nil;
  while (runner1 != list1 || runner2 != list2 || carry != 0) {
    Node *x = (Node*)malloc(sizeof(Node));
    int sum = carry;
    if (runner1 != list1) {
      sum += runner1->key;
      runner1 = runner1->next;
    }
    if (runner2 != list2) {
      sum += runner2->key;
      runner2 = runner2->next;
    }
    carry = sum / 10;
    x->key = sum % 10;
    cur->next = x;
    x->next = nil;
    cur = cur->next;
  }

  cur = nil->next;
  while (cur != nil) {
    cout << cur->key << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  int n, key;
  Node *head1 = (Node *)malloc(sizeof(Node));
  Node *head2 = (Node *)malloc(sizeof(Node));
  head1->next = head1;
  head2->next = head2;

  cin >> n;
  Node *cur = head1;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    cur->next = x;
    x->next = head1;
    cur = cur->next;
  }

  cin >> n;
  cur = head2;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    cur->next = x;
    x->next = head2;
    cur = cur->next;
  }

  addLinkedList(head1, head2);

  return 0;
}
