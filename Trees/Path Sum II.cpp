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

	void helper(TreeNode* node, int contri, int& targetSum, vector<int> currPath, vector<vector<int>>& res) {

		if (!node)
			return;

		if (contri + node->val == targetSum && !node->left && !node->right) {
			currPath.push_back(node->val);
			res.push_back(currPath);
		}


		// Recursive
		currPath.push_back(node->val);
		helper(node->left, contri + node->val, targetSum, currPath, res);
		helper(node->right, contri + node->val, targetSum, currPath, res);

		return;
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		int contri = 0;
		helper(root, contri, targetSum, {}, res);
		return res;
	}
};