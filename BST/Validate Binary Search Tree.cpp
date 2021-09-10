/*
	Using Custom Struct.
	$ : 50 / 80 test cases passed.
	  : I/P : [0,-1]
	  : O/P : false, expected : true
	# : This tc passed by replacing < & > with <= & >= since in a left/right skewed tree null would also be taken into consideration.
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

	struct bstData {
		int minVal;
		int maxVal;
		bool res;
	};

	bstData helper(TreeNode* node) {

		// Base case.
		if (!node) {
			bstData obj;
			obj.minVal = 0;
			obj.maxVal = 0;
			obj.res = true;
			return obj;
		}

		/* Leaf node */
		if (!node->left && !node->right) {
			bstData obj;
			obj.minVal = node->val;
			obj.maxVal = node->val;
			obj.res = true;
			return obj;
		}

		bstData ans;

		bstData leftCheck = helper(node->left);
		bstData rightCheck = helper(node->right);

		if (leftCheck.maxVal < node->val && rightCheck.minVal > node->val) {
			ans.res = true;
		} else {
			ans.res = false;
		}

		// Updating the max & min values.

		ans.minVal = min(ans.minVal, min(leftCheck.minVal, rightCheck.minVal));
		ans.maxVal = max(ans.maxVal, max(leftCheck.maxVal, rightCheck.maxVal));

		return ans;

	}


	bool isValidBST(TreeNode* root) {
		bstData res = helper(root);
		return res.res;
	}
};

/*
	Changed condition  if( (node->left ? leftCheck.maxVal<node->val : 1) && (node->right ? rightCheck.minVal>node->val : 1))
	$ : 59 / 80 test cases passed.
	  : [3,1,5,0,2,4,6] , O/P : false, exp: true
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

	struct bstData {
		int minVal;
		int maxVal;
		bool res;
	};

	bstData helper(TreeNode* node) {

		// Base case.
		if (!node) {
			bstData obj;
			obj.minVal = 0;
			obj.maxVal = 0;
			obj.res = true;
			return obj;
		}

		/* Leaf node */
		if (!node->left && !node->right) {
			bstData obj;
			obj.minVal = node->val;
			obj.maxVal = node->val;
			obj.res = true;
			return obj;
		}

		bstData ans;

		bstData leftCheck = helper(node->left);
		bstData rightCheck = helper(node->right);

		if ( (node->left ? leftCheck.maxVal < node->val : 1) && (node->right ? rightCheck.minVal > node->val : 1)) {
			ans.res = true;
		} else {
			ans.res = false;
		}

		// Updating the max & min values.

		ans.minVal = min(ans.minVal, min(leftCheck.minVal, rightCheck.minVal));
		ans.maxVal = max(ans.maxVal, max(leftCheck.maxVal, rightCheck.maxVal));

		return ans;

	}


	bool isValidBST(TreeNode* root) {
		bstData res = helper(root);
		return res.res;
	}
};

/*
	Simple Range approach. Pass the range as (-inf,+inf) for the root node, call on left with range (-inf,+node->val)
	and on right with range (node->val,+inf);
	$ : 72/80, I/P : [2147483647], O/P : false, expected : true
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

	bool helper(TreeNode* node, int minVal, int maxVal) {

		// Base Case.
		if (!node) {
			return true;
		}

		// Recursive.
		return (node->val > minVal && node->val < maxVal) && helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);

	}

	bool isValidBST(TreeNode* root) {
		// Using Range approach
		return helper(root, INT_MIN, INT_MAX);
	}
};

/*
	Runtime Error : Line 30: Char 35: runtime error: signed integer overflow: -2147483648 - 1 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:39:35

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

	bool helper(TreeNode* node, long int minVal, long int maxVal) {

		// Base Case.
		if (!node) {
			return true;
		}

		// Recursive.
		return (node->val > minVal && node->val < maxVal) && helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);

	}


	bool isValidBST(TreeNode* root) {
		// Using Range approach
		return helper(root, INT_MIN - 1, INT_MAX + 1);
	}
};

/*
	Type casted with (long int)
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

	bool helper(TreeNode* node, long int minVal, long int maxVal) {

		// Base Case.
		if (!node) {
			return true;
		}

		// Recursive.
		return (node->val > minVal && node->val < maxVal) && helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);

	}


	bool isValidBST(TreeNode* root) {
		// Using Range approach
		return helper(root, (long int)INT_MIN - 1, (long int)INT_MAX + 1);
	}
};