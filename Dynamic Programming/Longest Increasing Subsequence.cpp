/*
	$ : WA
	I/P : [4,10,4,3,8,9]
	O/P : 4
	Exp : 3

*/

class Solution {
public:

	int helper(vector<int>& nums, int idx) {

		// Base Case
		if (idx == nums.size() - 1)
			return 1;

		if (nums[idx + 1] > nums[idx]) {
			return 1 + helper(nums, idx + 1);
		} else {
			return helper(nums, idx + 1);
		}

	}

	int lengthOfLIS(vector<int>& nums) {
		return helper(nums, 0);
	}
};

/*
	WIP, WA
*/

class Solution {
public:

	int helper(vector<int>& nums, int idx, int& comp) {

		// Base Case
		if (idx == nums.size() - 1)
			return 0;

		// Take if possible

		int take = 0;

		if (nums[idx + 1] > comp) {
			comp = nums[idx + 1];
			take = 1 + helper(nums, idx + 1, comp);
		}

		int notTake = helper(nums, idx + 1, comp);

		return max(take, notTake);

	}

	int lengthOfLIS(vector<int>& nums) {
		int comp = nums[0];
		return 2 + helper(nums, 0, comp);
	}
};