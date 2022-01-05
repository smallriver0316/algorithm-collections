#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
};

Node *findLoop(Node *head) {
  // slow_runner moves by one node
  // fast_runner moves by two nodes
  Node *slow_runner = head->next;
  Node *fast_runner = head->next->next;

  // It assumes the length of non-loop is k.
  // When fast_runner reaches start of loop, slow_runner is k-th node and fast_runner is 2k-th node.
  // On loop, interval between slow_runner and fast_runner is 2k -k = k nodes.
  // From fast_runner, slow_runner is (loop size - k) nodes in front of fast_runner.
  // So, after that, two runners meet after (loop size - k) steps.
  while (slow_runner != fast_runner) {
    if (slow_runner == nullptr || fast_runner == nullptr) {
      return nullptr;
    }
    slow_runner = slow_runner->next;
    fast_runner = fast_runner->next->next;
  }

  // After that, if fast_runner moves k steps by one node, it will reach the start of loop; (loop size - k) + k = loop size.
  // Therefore, set slow_runner to the head of linked list again and move both of runners by one node.
  // When they meets again, the node must be loop start position.
  slow_runner = head;
  while (slow_runner != fast_runner) {
    slow_runner = slow_runner->next;
    fast_runner = fast_runner->next;
  }

  return slow_runner;
}

int main() {
  int n, key, k;
  Node *head = (Node *)malloc(sizeof(Node));

  cin >> n;
  Node *runner = head;
  for (int i = 0; i < n; i++) {
    cin >> key;
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    runner->next = x;
    runner = runner->next;
  }

  runner->next = nullptr;

  cin >> k;
  if (k > n - 1) {
    cout << "Start of loop must be less than loop end index" << endl;
    return 1;
  }

  Node *end = runner;
  runner = head->next;
  for (int i = 0; i < k; i++) {
    runner = runner->next;
  }
  end->next = runner;

  Node *ret = findLoop(head);
  if (ret == nullptr) {
    cout << "There is no loop" << endl;
  } else {
    cout << ret->key << endl;
  }

  return 0;
}
