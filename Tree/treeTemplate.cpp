// Template for tree problems
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};


void solve(Node *root) {
    //add your code here
}


int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    solve(root);

    return 0;
}