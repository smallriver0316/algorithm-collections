#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

void printList(Node* list) {
  Node *cur = list->next;
  while (cur != nullptr) {
    cout << cur->key << " ";
    cur = cur->next;
  }
  cout << endl;
}

void padList(Node* list, int size) {
  if (size <= 0) {
    return;
  }
  while (size > 0) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = 0;
    x->next = list->next;
    list->next = x;
    size--;
  }
}

int calcCarry(Node *list1, Node* list2) {
  if (list1->next == nullptr || list2->next == nullptr)
    return 0;

  int sum = list1->next->key + list2->next->key + calcCarry(list1->next, list2->next);
  return sum / 10;
}

Node* addLinkedList(Node *list1, Node *list2) {
  Node *head = (Node *)malloc(sizeof(Node));
  head->next = nullptr;
  Node *runner1 = list1;
  Node *runner2 = list2;
  Node *runner3 = head;

  while (runner1 != nullptr && runner2 != nullptr) {
    unsigned int carry = calcCarry(runner1, runner2);
    unsigned int sum = carry;
    if (runner1 != list1) {
      sum += runner1->key;
    }
    if (runner2 != list2) {
      sum += runner2->key;
    }

    if (sum > 0) {
      Node *x = (Node*)malloc(sizeof(Node));
      x->key = sum % 10;
      x->next = runner3->next;
      runner3->next = x;

      runner3 = runner3->next;
    }

    runner1 = runner1->next;
    runner2 = runner2->next;
  }

  return head;
}

int main() {
  int n1, n2, key;
  Node *head1 = (Node *)malloc(sizeof(Node));
  Node *head2 = (Node *)malloc(sizeof(Node));
  head1->next = nullptr;
  head2->next = nullptr;

  Node *cur = head1;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = cur->next;
    cur->next = x;
    cur = cur->next;
  }

  cur = head2;
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = cur->next;
    cur->next = x;
    cur = cur->next;
  }

  padList(head1, n2 - n1);
  padList(head2, n1 - n2);

  Node *output = addLinkedList(head1, head2);

  printList(output);

  return 0;
}
