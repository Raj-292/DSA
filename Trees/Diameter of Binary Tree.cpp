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


/*
    Simpler soln, same complexity
    $ : AC (TUF)
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

private:

    int helper(TreeNode* node, int& res) {
        if (!node)
            return 0;

        int leftHeight = helper(node->left, res);
        int rightHeight = helper(node->right, res);

        res = max(res, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int temp =  helper(root, res);
        return res;
    }
};