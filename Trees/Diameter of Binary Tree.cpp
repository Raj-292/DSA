/*
    $ : AC
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> helper(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        pair<int, int> left = helper(node->left);
        pair<int, int> right = helper(node->right);
        int leftDia = left.second;
        int leftHeight = left.first;
        int rightDia = right.second;
        int rightHeight = right.first;

        int height = 1 + max(leftHeight, rightHeight);
        int diameter = max({leftHeight + rightHeight, leftDia, rightDia});

        return {height, diameter};

    }

    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};