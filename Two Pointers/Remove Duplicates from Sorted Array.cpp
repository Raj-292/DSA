/*
	$ : AC
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int p1 = 0;
		int p2 = 0;
		int idx = 0;

		while (p2 < nums.size()) {

			while (p2 < nums.size() && nums[p1] == nums[p2]) {
				p2++;
			}

			nums[idx] = nums[p1];
			idx++;
			p1 = p2;

		}

		return idx;

	}
};