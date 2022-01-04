#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

Node* hasCommonNodes(Node *head1, Node *head2) {
  Node *runner1 = head1;
  Node *runner2 = head2;
  int size1 = 0;
  int size2 = 0;

  while (runner1->next != nullptr) {
    runner1 = runner1->next;
    size1++;
  }

  while (runner2->next != nullptr) {
    runner2 = runner2->next;
    size2++;
  }

  if (runner1 != runner2) {
    return nullptr;
  }

  int offset;
  runner1 = head1->next;
  runner2 = head2->next;

  if (size1 > size2) {
    offset = size1 - size2;
    while (offset > 0) {
      runner1 = runner1->next;
      offset--;
    }
  } else if (size2 > size1) {
    offset = size2 - size1;
    while (offset > 0) {
      runner2 = runner2->next;
      offset--;
    }
  }

  while (runner1 != runner2) {
    runner1 = runner1->next;
    runner2 = runner2->next;
  }

  return runner1;
}

int main() {
  int n, key;
  Node *head1 = (Node *)malloc(sizeof(Node));
  Node *head2 = (Node *)malloc(sizeof(Node));
  head1->next = nullptr;
  head2->next = nullptr;

  // input distinct nodes of first linked list
  cin >> n;
  Node *runner1 = head1;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = runner1->next;
    runner1->next = x;
    runner1 = runner1->next;
  }

  // input distinct nodes of second linked list
  cin >> n;
  Node *runner2 = head2;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = runner2->next;
    runner2->next = x;
    runner2 = runner2->next;
  }

  // input common nodes if the length is more than zero.
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = runner1->next;
    runner1->next = x;
    if (i == 0) {
      runner2->next = x;
    }
    runner1 = runner1->next;
  }

  Node *common = hasCommonNodes(head1, head2);
  if (common == nullptr) {
    cout << "False" << endl;
  } else {
    cout << "True" << endl;
    Node *runner = common;
    while (runner != nullptr) {
      cout << runner->key << " ";
      runner = runner->next;
    }
    cout << endl;
  }

  return 0;
}
