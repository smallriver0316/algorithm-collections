#include <iostream>
using namespace std;

#define MAX 100
#define NIL -1

/*
    n: number of nodes
    P: preorder of tree node
    I: inorder of tree ndoe
*/
int n, P[MAX], I[MAX];

/*
    Print Postorder from Inorder array.
    This tree is binary tree.
    Inorder is left -> node -> right and node is obtained from Preorder array.
    So left side items against the node in Inorder array are left children.
    On the other hand, right side items against the node in Inorder array are right children.
    Therefore, print as left side, right side and node, Postorder is created.
 
    start: start position in Inorder
    end: end positon in Inorder
    node_idx: node index in Preorder
*/
void printPostorder(int start, int end, int node_idx)
{
    if (node_idx > n - 1)
        return;

    int node = P[node_idx];
    int node_pos = -1; // node position in Inorder
    // search node position
    for (int i = start; i <= end; i++)
    {
        if (I[i] == node)
        {
            node_pos = i;
            break;
        }
    }
    if (node_pos == -1)
    {
        printPostorder(start, end, ++node_idx);
        return;
    }

    // print left children
    int left_s = start;
    int left_e = node_pos;
    if (left_e - left_s > 1)
    {
        printPostorder(left_s, left_e - 1, ++node_idx);
    }
    else if (left_e - left_s == 1)
    {
        cout << I[left_s] << " ";
    }

    // print right children
    int right_s = node_pos;
    int right_e = end;
    if (right_e - right_s > 1)
    {
        printPostorder(right_s + 1, right_e, ++node_idx);
    }
    else if (right_e - right_s == 1)
    {
        cout << I[right_e] << " ";
    }
    // print node
    cout << node << " ";
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> I[i];
    }

    printPostorder(0, n - 1, 0);
    cout << endl;

    return 0;
}
