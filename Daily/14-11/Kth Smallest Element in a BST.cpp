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

private:

	void inorderTraversal(TreeNode* node, vector<int>& sortedNodes) {

		// Base Case
		if (!node)
			return;

		// Left Sub-tree
		inorderTraversal(node->left, sortedNodes);

		// Store current node to the vector
		sortedNodes.push_back(node->val);

		// Right Sub-tree
		inorderTraversal(node->right, sortedNodes);

	}

public:
	int kthSmallest(TreeNode* root, int k) {

		vector<int> sortedNodes;

		// Inorder traversal
		inorderTraversal(root, sortedNodes);

		// Return the element at k-1 index
		return sortedNodes[k - 1];

	}
};