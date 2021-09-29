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

    void helper(TreeNode* node, int depth, int& maxDepth, int& sum) {

        if (!node)
            return;

        if (depth == maxDepth) {
            sum += node->val;
        } else if (depth > maxDepth) {
            sum = node->val;
            maxDepth = depth;
        }

        helper(node->left, depth + 1, maxDepth, sum);
        helper(node->right, depth + 1, maxDepth, sum);

    }

    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        int maxDepth = 0;
        int sum = 0;
        helper(root, depth, maxDepth, sum);
        return sum;
    }
};