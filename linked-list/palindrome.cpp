#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

/*
  This struct is used to both:
  1. tell the pair of node in palindrome
  2. inner pairs in palindrome are matched
*/
struct Result {
  Node* node;
  bool result;
};

Result isPalindromeRecurse(Node *node, int length) {
  Result res;
  if (node == nullptr) {
    res = { node, true };
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
    res = isPalindromeRecurse(node->next, length - 2);
    if (res.result && res.node != nullptr) {
      res.result = node->key == res.node->key;
      res.node = res.node->next;
    }
  }
  return res;
}

bool isPalindrome(Node *head, int length) {
  Result res = isPalindromeRecurse(head->next, length);
  return res.result;
}

int main() {
  int n, key;
  Node *nil = (Node*)malloc(sizeof(Node));
  nil->next = nullptr;

  cin >> n;
  Node *runner = nil;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->next = runner->next;
    runner->next = x;
    runner = runner->next;
  }

  if (isPalindrome(nil, n)) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  return 0;
}
