/*
	$ : AC
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		// Make a copy of nums (also preserve original index)
		vector<pair<int, int>> numsCopy(nums.size()); // first -> value, second -> original index
		for (int i = 0 ; i < nums.size() ; i++) {
			numsCopy[i] = {nums[i], i};
		}

		// Sort O(NlogN)
		sort(numsCopy.begin(), numsCopy.end());

		vector<int> res;

		int ptr1 = 0;
		int ptr2 = nums.size() - 1;

		while (ptr1 < ptr2) {
			int tempSum = numsCopy[ptr1].first + numsCopy[ptr2].first;
			if (tempSum == target) {
				res.push_back(numsCopy[ptr1].second);
				res.push_back(numsCopy[ptr2].second);
				break;
			} else if (tempSum < target) {
				ptr1++;
			} else {
				ptr2--;
			}

		}
		return res;
	}
};