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

/*
	Iterative soln, no need of extra sortedNodes array
	$ : AC
*/

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		TreeNode* node = root;
		int cnt = 0;
		while (true) {
			if (node != NULL) {
				st.push(node);
				node = node->left;
			}
			else {
				if (st.empty() == true) break;
				node = st.top();
				st.pop();
				// inorder.push_back(node->val);
				cnt++;
				if (cnt == k) return node->val;
				node = node->right;
			}
		}
		return -1;
	}
};
