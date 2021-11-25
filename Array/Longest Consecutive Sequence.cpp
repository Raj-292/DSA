/*
	Optimized
	Idea :  Create a set of all the elts in nums
	Iterate through nums, for any given nums[i] if nums[i-1] exists in set, ignore and continue
	If it does not, keep on increasing the count by 1 as long as the resultant element is present in set
	The idea here is to start from the minimum element in the series
	$ : AC
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		// Constructing a set to keep all the elements
		unordered_set<int> numsSet;

		for (const int& x : nums)
			numsSet.insert(x);

		// Initializing the res as 0
		int res = 0;

		// Traversing nums
		for (const int& x : nums) {
			// Ignore if x-1 exists
			if (numsSet.find(x - 1) != numsSet.end())
				continue;

			// If x-1 does not exist, keep on adding as long as a greater element is present
			int currRes = 1;
			int temp = x;
			while (numsSet.find(temp + 1) != numsSet.end()) {
				currRes++;
				temp++;
			}
			res = max(res, currRes);
		}

		return res;
	}
};

/*
	SV
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> hashSet;
		for (int num : nums) {
			hashSet.insert(num);
		}

		int longestStreak = 0;

		for (int num : nums) {
			if (!hashSet.count(num - 1)) {
				int currentNum = num;
				int currentStreak = 1;

				while (hashSet.count(currentNum + 1)) {
					currentNum += 1;
					currentStreak += 1;
				}

				longestStreak = max(longestStreak, currentStreak);
			}
		}

		return longestStreak;
	}
};

