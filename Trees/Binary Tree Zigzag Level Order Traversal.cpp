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

    vector<vector<int>> helper(TreeNode* node) {

        // Base Case
        if (!node)
            return {};

        vector<vector<int>> res;

        queue<TreeNode*> q;

        // Push root to the queue
        q.push(node);
        bool isReversed = false;

        while (!q.empty()) {

            int currSize = q.size();
            vector<int> levelArray;

            while (currSize--) {
                TreeNode* frontNode = q.front();
                q.pop();
                levelArray.push_back(frontNode->val);
                // Adding left and right child to the queue
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);

            }

            // Pushing the current level to res vector
            if (isReversed)
                reverse(levelArray.begin(), levelArray.end());
            res.push_back(levelArray);
            isReversed = !isReversed;
        }

        return res;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return helper(root);
    }
};