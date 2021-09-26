/*
	Difficulty : HARD
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

	TreeNode* getSuccessor(TreeNode* node) {
		node = node->right;
		while (node && node->left) {
			node = node -> left;
		}

		return node;
	}

	TreeNode* helper(TreeNode* node, int key) {
		if (!node) {
			return NULL;
		}

		if (node->val > key) {
			node->left = helper(node->left, key);
		} else if (node->val < key) {
			node->right = helper(node->right, key);
		} else {
			if (!node->left) {
				TreeNode* temp = node->right;
				delete node;
				return temp;
			} else if (!node->right) {
				TreeNode* temp = node->left;
				delete node;
				return temp;
			} else {
				TreeNode* succ = getSuccessor(node);
				node->val = succ->val;
				node->right = helper(node->right, succ->val);
			}

		}

		return node;
	}


	TreeNode* deleteNode(TreeNode* root, int key) {
		return helper(root, key);
	}
};