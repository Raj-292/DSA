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

	bool hasPathSumHelper(TreeNode* node, int targetSum, int& cumSum) {

		if (!node)
			return false;

		if (!node->left && !node->right) {
			if (cumSum + node->val == targetSum)
				return true;
		}

		int cumSumOld = cumSum;

		// Adding node-val to cumSum
		cumSum += node->val;

		bool left = hasPathSumHelper(node->left, targetSum, cumSum);
		bool right = hasPathSumHelper(node->right, targetSum, cumSum);

		// Reset cumSum
		cumSum = cumSumOld;

		return left || right;

	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		int cumSum = 0;
		return hasPathSumHelper(root, targetSum, cumSum);
	}
};