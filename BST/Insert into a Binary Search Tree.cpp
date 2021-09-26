/*
	TC failing, I/P : [40,20,60,10,30,50,70], 25
				O/P : [40,20,60,10,30,50,70]
				Exp : [40,20,60,10,30,50,70,null,null,25]
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

	void helper(TreeNode* node, int val) {

		// Base Case.
		if (!node) {
			return;
		}

		if (!node->left && !node->right) {
			if (node->val < val) {
				node->right = new TreeNode(val);
			} else {
				node->left = new TreeNode(val);
			}
		}


		// Recursive

		if (node->val < val) {
			helper(node->right, val);
		}


	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		helper(root, val);
		return root;
	}
};

/*
	Else statement was missing : else {
            helper(node->left,val);
        }

     Giving TLE on same TC => need a return statement too after attaching a new node

     $ : 22 / 35 test cases passed.
     Input:[5,null,14,10,77,null,null,null,95,null,null],4
     Output : [5,null,14,10,77,null,null,null,95]
     Expected : [5,4,14,null,null,10,77,null,null,null,95]
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

	void helper(TreeNode* node, int val) {

		// Base Case.
		if (!node) {
			return;
		}

		if (!node->left && !node->right) {
			if (node->val < val) {
				node->right = new TreeNode(val);
			} else {
				node->left = new TreeNode(val);
			}
			return;
		}

		// Recursive

		if (node->val < val) {
			helper(node->right, val);
		} else {
			helper(node->left, val);
		}

	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		helper(root, val);
		return root;
	}
};

/*
	Changed the insert logic
	$ : 19 / 35 test cases passed.
	I/P : [61,46,66,43,null,null,null,39,null,null,null],88
	O/P : [61,46,66,43,null,null,88,39,null,88]
	Exp : [61,46,66,43,null,null,88,39]
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

	void helper(TreeNode* node, int val) {

		// Base Case.
		if (!node) {

			return;
		}

		if (node->val < val) {
			if (!node->right) {
				node->right = new TreeNode(val);
			}
			helper(node->right, val);
		} else {
			if (!node->left) {
				node->left = new TreeNode(val);
				return;
			}
			helper(node->left, val);
		}

	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		helper(root, val);
		return root;
	}
};

/*
	There was a missing return statement after node->right = new TreeNode(val);
	$ : 34 / 35 test cases passed.
	I/P : [],5
	O/P : []
	Expected : [5]
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

	void helper(TreeNode* node, int val) {

		// Base Case.
		if (!node) {

			return;
		}

		if (node->val < val) {
			if (!node->right) {
				node->right = new TreeNode(val);
				return;
			}
			helper(node->right, val);
		} else {
			if (!node->left) {
				node->left = new TreeNode(val);
				return;
			}
			helper(node->left, val);
		}

	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		helper(root, val);
		return root;
	}
};

/*
	Added NULL check
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

	void helper(TreeNode* node, int val) {

		// Base Case.
		if (!node) {

			return;
		}

		if (node->val < val) {
			if (!node->right) {
				node->right = new TreeNode(val);
				return;
			}
			helper(node->right, val);
		} else {
			if (!node->left) {
				node->left = new TreeNode(val);
				return;
			}
			helper(node->left, val);
		}

	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root) {
			return new TreeNode(val);
		}
		helper(root, val);
		return root;
	}
};

/*
	The Above solution also works without the base case since that is never reached and the execution is breaked before it reaches NULL ptr;
*/