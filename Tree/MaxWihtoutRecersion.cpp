#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

// int max(int x, int y) {
//     return x > y ? x : y;
// }

int maxElement(Node *root)
{
    if (!root)
    {
        return INT_MIN;
    }

    /**
     * Do level order traversal to get max element
     */
    int max_ele = INT_MIN;
    queue<Node *> q; // creating queue
    q.push(root);    // 1
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        max_ele = max(temp->data, max_ele);

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    return max_ele;
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    cout << maxElement(root) <<"\n";
    return 0;
}