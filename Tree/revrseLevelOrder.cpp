// Template for tree problems
#include <iostream>
#include <queue>
#include <stack>

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


void reverseLevelOrder(Node *root) {
    //add your code here
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    stack<Node *> stk;
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->left) {
            q.push(temp->left);}
        if(temp->right){
            q.push(temp->right);}
        stk.push(temp);
    }
    while(!stk.empty()){
        cout<< stk.top()->data << " ";
        stk.pop();
    }
}


int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    reverseLevelOrder(root);

    return 0;
}