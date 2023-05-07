#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

int MaxElement(struct Node *root)
{
    if (!root)
        return INT_MIN;
    int max_ele = INT_MIN;
    int curr = root->data;
    int left = MaxElement(root->left);
    int right = MaxElement(root->right);
    // finding the largest
    max_ele = max(max_ele, max(curr, max(left, right)));
    return max_ele;
}

// crteating a new tree
Node *newNode(int data) // creating a new tree node
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};

int main()
{
    // Let us create binary tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Maximum Element of the tree is : " << MaxElement(root) << "\n";
    return 0;
}
