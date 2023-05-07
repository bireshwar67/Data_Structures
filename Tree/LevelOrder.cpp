#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
// Finding height of the tree

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    // creating empty queue
    queue<Node *> q;
    q.push(root); // enqueueing the root intialize height
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (!node) {
            cout << "\n";
            if (!q.empty()) {
                q.push(NULL);
            }
            continue;
        }

        cout << node->data << " "; // print front and pop front

        if (node->left)
        {
            q.push(node->left);
        }
        
        if (node->right)
        {
            q.push(node->right);
        }
    }
}

Node *newNode(int data) // creating a new tree node
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    levelOrder(root);
    return 0;
}
