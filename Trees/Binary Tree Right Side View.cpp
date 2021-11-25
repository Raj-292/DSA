/*
	$ : WA, 211 / 215 test cases passed.
	I/P : [6,3,null,1,5,null,2,4]
	O/P : [6,3,5,2]
	Exp : [6,3,5,4]
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

	void traverse(TreeNode* node, int level, int hd, map<int, pair<int, int>>& mp) {

		// Base Case
		if (!node)
			return;

		if (mp[level].second == 0) {
			mp[level].second = hd;
			mp[level].first = node->val;
		}

		else {
			if (mp[level].second < hd) {
				mp[level].second = hd;
				mp[level].first = node->val;
			}
		}

		// Recursive
		if (node->left) {
			traverse(node->left, level + 1, hd - 1, mp);
		}

		if (node->right) {
			traverse(node->right, level + 1, hd + 1, mp);
		}

	}

	vector<int> rightSideView(TreeNode* root) {

		map<int, pair<int, int>> mp; // In pair, first : node->val, second : hd
		traverse(root, 0, 0, mp);

		vector<int> res;

		for (auto x : mp)
			res.push_back(x.second.first);

		return res;
	}

};

/*
	In case of equal depth and equal horizontal distance, we should be considering the one which comes later
	i.e the node which is to the right. Hence, replaced the condition to be mp[level].second <= hd
	Above failing TC passed
	$ : WA, 213 / 215 test cases passed.
	I/P : [0,1,2,null,3,4,null,null,5,9,null,null,6,10,null]
	O/P : [0,2,4,5,6]
	Exp : [0,2,4,9,10]
*/