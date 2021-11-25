/*
	$ : AC
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		if (nums.size() == 1)
			return;

		int n = nums.size();
		int pos, i;

		for (i = n - 2; i >= 0  && nums[i] >= nums[i + 1]; i--);
		pos = i;

		if (pos >= 0 ) {
			int minGreaterThanPos = INT_MAX;
			int minIdx = pos;
			for (int i = pos + 1; i < n ; i++) {
				if (nums[i] > nums[pos]) {
					if (nums[i] <= minGreaterThanPos) {
						minGreaterThanPos = nums[i];
						minIdx = i;
					}
				}
			}

			// Swap
			swap(nums[pos], nums[minIdx]);

			// Reverse pos+1 ... n-1
			reverse(nums.begin() + pos + 1, nums.end());

		} else {
			reverse(nums.begin(), nums.end());
		}
	}
};