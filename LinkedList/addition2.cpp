#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

void printList(Node* list) {
  Node *cur = list->next;
  while (cur != list) {
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

int calcCarry(Node *list1, Node* list2, Node *anchor1, Node *anchor2) {
  if (list1->next == anchor1 || list2->next == anchor2)
    return 0;

  int sum = list1->next->key + list2->next->key + calcCarry(list1->next, list2->next, anchor1, anchor2);
  return sum / 10;
}

Node* addLinkedList(Node *list1, Node *list2, int digit) {
  Node *head = (Node *)malloc(sizeof(Node));
  head->next = head;
  Node *runner1 = list1;
  Node *runner2 = list2;
  Node *runner3 = head;

  // increment +1 in order to deal with carry of largest digit
  int counter = digit + 1;

  while (counter > 0) {
    unsigned int carry = calcCarry(runner1, runner2, list1, list2);
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
      runner3->next = x;
      x->next = head;

      runner3 = runner3->next;
    }

    runner1 = runner1->next;
    runner2 = runner2->next;

    counter--;
  }

  return head;
}

int main() {
  int n1, n2, key;
  Node *head1 = (Node *)malloc(sizeof(Node));
  Node *head2 = (Node *)malloc(sizeof(Node));
  head1->next = head1;
  head2->next = head2;

  Node *cur = head1;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    cur->next = x;
    x->next = head1;
    cur = cur->next;
  }

  cur = head2;
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    cur->next = x;
    x->next = head2;
    cur = cur->next;
  }

  padList(head1, n2 - n1);
  padList(head2, n1 - n2);

  Node *output = addLinkedList(head1, head2, n1 > n2 ? n1 : n2);

  printList(output);

  return 0;
}
