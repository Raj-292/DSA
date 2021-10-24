/*
	O(nlogn) time and O(1) aux. space
	$ : AC
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {

		// Sort
		sort(nums.begin(), nums.end());

		return nums[ceil(nums.size() / 2)];
	}
};