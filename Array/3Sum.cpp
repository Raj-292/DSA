/*
	$ : WA
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		// Sort
		sort(nums.begin(), nums.end());

		set<vector<int>> res;

		// Select a number, 2sum on the remaining ones with the target being -(selected number)
		for (int i = 0 ; i < nums.size() ; i++) {

			int target = -nums[i];

			int ptr1 = 0;
			int ptr2 = nums.size() - 1;

			while (ptr1 < ptr2) {

				if (ptr1 == i) {
					ptr1++;
					continue;
				}

				if (ptr2 == i) {
					ptr2--;
					continue;
				}

				if (nums[ptr1] + nums[ptr2] == target) {
					vector<int> vec = {nums[ptr1], nums[ptr2], nums[i]};
					sort(vec.begin(), vec.end());
					res.insert(vec);
					break;
				}
				else if (nums[ptr1] + nums[ptr2] < target)
					ptr1++;
				else
					ptr2--;
			}

		}

		vector<vector<int>> ans(res.begin(), res.end());

		return ans;
	}
};