/*
	AddressSanitizer:DEADLYSIGNAL
	=================================================================
	==31==ERROR: AddressSanitizer: stack-overflow on address 0x7ffdaaa4aff8 (pc 0x0000002a04c6 bp 0x000000000018 sp 0x7ffdaaa4afe0 T0)
	==31==ABORTING
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

	TreeNode* helper(vector<int>& nums, vector<int>::iterator itrStart, vector<int>::iterator itrEnd) {

		// Base Case.
		if (nums.size() == 0 ) {
			return NULL;
		}

		// Recursive.
		int midIdx = floor((itrEnd - itrStart) / 2);

		TreeNode* node = new TreeNode(nums[midIdx]);

		// Getting the left & right Sub-trees.
		TreeNode* leftSubtree = helper(nums, itrStart, itrStart + midIdx);
		TreeNode* rightSubtree = helper(nums, itrStart + midIdx, itrEnd);

		// Construct the object
		node->left = leftSubtree;
		node->right = rightSubtree;

		return node;

	}


	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, nums.begin(), nums.end());
	}
};

/*
	Trying with integer indexes instead of iterators.
	Infinite loop - eg: intStart = 3, Intend = 3, mid would become 0 which is incorrect;
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

	TreeNode* helper(vector<int>& nums, int itrStart, int itrEnd) {


		// Base Case.
		if (itrEnd <= 0 || itrStart > itrEnd) {
			return NULL;
		}


		cout << "itrStart : " << itrStart << " & itrEnd : " << itrEnd << endl;


		// Recursive.
		int midIdx = floor((itrEnd - itrStart) / 2);

		TreeNode* node = new TreeNode(nums[midIdx]);

		// Getting the left & right Sub-trees.
		TreeNode* leftSubtree = helper(nums, itrStart, midIdx - 1);
		TreeNode* rightSubtree = helper(nums, midIdx + 1, itrEnd);

		// Construct the object
		node->left = leftSubtree;
		node->right = rightSubtree;

		return node;

	}


	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};

/*
	In midIdx, definiton, adding itrStart is necessary. => int midIdx = itrStart + floor((itrEnd - itrStart) / 2);
	$ : 11 / 31 test cases passed. I/P:[0] O/P : [] , exp : [0]

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

	TreeNode* helper(vector<int>& nums, int itrStart, int itrEnd) {

		// Base Case.
		if (itrEnd <= 0 || itrStart > itrEnd) {
			return NULL;
		}

		// Recursive.
		int midIdx = itrStart + floor((itrEnd - itrStart) / 2);

		TreeNode* node = new TreeNode(nums[midIdx]);

		// Getting the left & right Sub-trees.
		TreeNode* leftSubtree = helper(nums, itrStart, midIdx - 1);
		TreeNode* rightSubtree = helper(nums, midIdx + 1, itrEnd);

		// Construct the object
		node->left = leftSubtree;
		node->right = rightSubtree;

		return node;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};

/*
	Removed unnecesaary base case condtion : itrEnd <= 0 . Which was causing above failure
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

	TreeNode* helper(vector<int>& nums, int itrStart, int itrEnd) {

		// Base Case.
		if (itrStart > itrEnd) {
			return NULL;
		}

		// Recursive.
		int midIdx = itrStart + floor((itrEnd - itrStart) / 2);

		TreeNode* node = new TreeNode(nums[midIdx]);

		// Getting the left & right Sub-trees.
		TreeNode* leftSubtree = helper(nums, itrStart, midIdx - 1);
		TreeNode* rightSubtree = helper(nums, midIdx + 1, itrEnd);

		// Construct the object
		node->left = leftSubtree;
		node->right = rightSubtree;

		return node;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};

/*
	Simpler
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

	TreeNode* helper(vector<int>& nums, int startIdx, int endIdx) {

		// Base Case
		if (startIdx > endIdx)
			return NULL;

		int mid = startIdx + (endIdx - startIdx) / 2;

		TreeNode* root = new TreeNode(nums[mid]);

		// Recursive
		TreeNode* leftSubTree = helper(nums, startIdx, mid - 1);
		TreeNode* rightSubTree = helper(nums, mid + 1, endIdx);

		// Connect
		root->left = leftSubTree;
		root->right = rightSubTree;

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {

		int n = nums.size();

		return helper(nums, 0, n - 1);
	}
};

