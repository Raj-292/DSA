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

	void helper(TreeNode* node, int low, int high, int& sum) {

		// base case
		if (!node) {
			return;
		}

		//recursive
		sum += (node->val <= high) && (node->val >= low) ? node->val : 0 ;

		if (node->val < high && node->val > low) {
			helper(node->left, low, high, sum);
			helper(node->right, low, high, sum);
		} else if (node->val < high) {
			helper(node->right, low, high, sum);
		} else if (node->val > low) {
			helper(node->left, low, high, sum);
		}

		return;
	}


	int rangeSumBST(TreeNode* root, int low, int high) {
		int res = 0;
		helper(root, low, high, res);
		return res;
	}
};