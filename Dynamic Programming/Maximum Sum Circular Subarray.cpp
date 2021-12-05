/*
	$ : AC (DSC)

	Explanation : https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass

	Max(suffix+prefix)
	Max(total-subarray)
	total+max(-subrray)
	total-min(subarray)

*/

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {

		int n = nums.size();

		int totalSum = nums[0];

		for (int i = 1 ; i < n ; i++)
			totalSum += nums[i];

		vector<int> currMax(n, -1);
		vector<int> currMin(n, -1);

		currMax[0] = nums[0];
		currMin[0] = nums[0];

		int res = nums[0];
		int maxCurrMax = nums[0];

		for (int i = 1 ; i < n ; i++) {
			currMax[i] = max(nums[i], currMax[i - 1] + nums[i]);
			currMin[i] = min(nums[i], currMin[i - 1] + nums[i]);
			res = max({res, currMax[i], totalSum - currMin[i]});
			// keeping track of maximum currMax encountered to handle case when all are negative
			maxCurrMax = max(currMax[i], maxCurrMax);
		}

		return res > 0 ? res : maxCurrMax;
	}
};