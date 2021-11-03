/*
	Failing for the first TC given because the current solution also considers nodes after previous nodes are ignored
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

	void helper(TreeNode* node, int& targetSum, int contri, int& res) {

		// Base Case

		if (!node)
			return;

		if (contri + node->val == targetSum) {
			cout << "One possible path ending at : " << node->val << endl;
			res++;
		}

		// Recursive
		// Left
		// Take if possible
		if (contri + node->val <= targetSum) {
			// Left
			helper(node->left, targetSum, contri + node->val, res);

			// Right
			helper(node->right, targetSum, contri + node->val, res);
		}

		// Not take
		// Left
		helper(node->left, targetSum, contri, res);
		// Right
		helper(node->right, targetSum, contri, res);
	}

	int pathSum(TreeNode* root, int targetSum) {
		int res = 0;
		helper(root, targetSum, 0, res);
		return res;
	}
};

/*
	Reset the contri to 0 when not taking
	$ : WA, 75 / 126 test cases passed.
	I/P : [-2,null,-3]
		  -5
	O/P : 0
	Exp : 1
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

	void helper(TreeNode* node, int& targetSum, int contri, int& res) {

		// Base Case

		if (!node)
			return;

		if (contri + node->val == targetSum) {
			res++;
		}


		// Recursive
		// Left
		// Take if possible
		if (contri + node->val <= targetSum) {
			// Left
			helper(node->left, targetSum, contri + node->val, res);

			// Right
			helper(node->right, targetSum, contri + node->val, res);
		}

		// Not take
		// Left
		helper(node->left, targetSum, 0, res);
		// Right
		helper(node->right, targetSum, 0, res);
	}

	int pathSum(TreeNode* root, int targetSum) {
		int res = 0;
		helper(root, targetSum, 0, res);
		return res;
	}
};

/*
	Removed the conditon for taking (since it will fail for negative target cases)
	$ : WA 100 / 126 test cases passed.
	I/P : [1,null,2,null,3,null,4,null,5]
		  3
	O/P : 3
	Exp : 2
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

	void helper(TreeNode* node, int& targetSum, int contri, int& res) {

		// Base Case
		if (!node)
			return;

		if (contri + node->val == targetSum) {
			res++;
		}

		// Recursive

		// Take
		// Left
		helper(node->left, targetSum, contri + node->val, res);

		// Right
		helper(node->right, targetSum, contri + node->val, res);

		// Not take
		// Left
		helper(node->left, targetSum, 0, res);
		// Right
		helper(node->right, targetSum, 0, res);
	}

	int pathSum(TreeNode* root, int targetSum) {
		int res = 0;
		helper(root, targetSum, 0, res);
		return res;
	}
};

/*
	Added return after res++
	$ : WA 99 / 126 test cases passed.
	I/P : [1,-2,-3,1,3,-2,null,-1]
		  3
	O/P : 2
	Exp : 1
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

	void helper(TreeNode* node, int& targetSum, int contri, int& res) {

		// Base Case
		if (!node)
			return;

		if (contri + node->val == targetSum) {
			res++;
			return;
		}

		// Recursive

		// Take
		// Left
		helper(node->left, targetSum, contri + node->val, res);

		// Right
		helper(node->right, targetSum, contri + node->val, res);

		// Not take
		// Left
		helper(node->left, targetSum, 0, res);
		// Right
		helper(node->right, targetSum, 0, res);
	}

	int pathSum(TreeNode* root, int targetSum) {
		int res = 0;
		helper(root, targetSum, 0, res);
		return res;
	}
};