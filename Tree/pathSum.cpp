#include <iostream>
using namespace std;

// Define the TreeNode structure and Solution class here...
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // If the current node is null, there is no path
        if (!root)
        {
            return false;
        }

        // If the current node is a leaf and its value equals the remaining target sum
        if (!root->left && !root->right && root->val == targetSum)
        {
            return true;
        }

        // Recursively check the left and right subtrees
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    cout << (sol.hasPathSum(root, targetSum) ? "True" : "False") << endl; // Expected output: True

    return 0;
}
