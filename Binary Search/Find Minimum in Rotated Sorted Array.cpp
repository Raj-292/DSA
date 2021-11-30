/*
	Using predicate framework
*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		// FFFFTTTTT
		// p(x): x <= nums[n-1]
		// First T

		int n = nums.size(), lo, hi, mid;

		lo = 0, hi = n - 1;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;

			if (nums[mid] < nums[0])
				hi = mid;
			else
				lo = mid + 1;
		}

		// [1, 2]
		// [2, 1]
		// [1, 2, 3, 4]
		// [11, 13, 15, 17]
		// Sanity check
		if (nums[lo] < nums[0])
			return nums[lo];
		return nums[0];
	}
};

