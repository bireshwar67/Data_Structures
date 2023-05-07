#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);	/* first recur on left child */
	cout << node->data << " ";	/* then print the data of node */
	printInorder(node->right);	/* now recur on right child */
}
void PreOrder(struct Node* root)
{
	if ( root == NULL)
	return;
	PreOrder(root->left);
	PreOrder(root->right);
	cout << root->data << " ";
}
void PostOrder(struct Node* root)
{
	if (root == NULL)
	return;
	cout << root->data << " ";
	PostOrder(root->left);
	PostOrder(root->right);
}
/* Driver code*/
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	// Function call

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);
	cout << "\nPreOrder Traversal of Binary Tree is \n";
	PreOrder(root);
	cout << "\nPostOrder Traversal of Binary Tree is \n";
	PostOrder(root);
	return 0;
}