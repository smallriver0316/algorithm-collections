#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

struct Result {
  Node* node;
  bool result;
};

Result isPalindromeRecurse(Node *node, Node *anchor, int length) {
  Result res;
  if (node == anchor) {
    res = { nullptr, true };
  } else if (length <= 0) {
    res = { node, true };
  } else if (length == 1) {
    res = { node->next, true };
  } else {
    // Here searches pair in palindrome.
    // Palindrome is symmetry, so the length is decremented by 2.
    // When the length becomes 1 or 0, it reaches smallest pair in palindrome, the center of it.
    // After that, stop to decrement length.
    // Instead of decrementing length, return result including the next node of current pair node.
    // This continues to head along the linked list.
    res = isPalindromeRecurse(node->next, anchor, length - 2);
    if (res.result && res.node != nullptr) {
      res.result = node->key == res.node->key;
      res.node = res.node->next;
    }
  }
  return res;
}

bool isPalindrome(Node *head, int length) {
  if (length < 2) {
    return false;
  }
  Result res = isPalindromeRecurse(head->next, head, length);
  return res.result;
}

int main() {
  int n, key;
  Node *nil = (Node*)malloc(sizeof(Node));
  nil->next = nil;

  cin >> n;
  Node *runner = nil;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    runner->next = x;
    x->next = nil;
    runner = runner->next;
  }

  if (isPalindrome(nil, n)) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  return 0;
}
