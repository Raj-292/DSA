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

	TreeNode* helper(TreeNode* node, int val) {

		//base case
		if (!node) {
			return NULL;
		}

		//recursive
		if (node->val == val)
			return node;

		if (node->val > val) {
			return helper(node->left, val);
		}

		return helper(node->right, val);

	}

	TreeNode* searchBST(TreeNode* root, int val) {
		return helper(root, val);
	}
};