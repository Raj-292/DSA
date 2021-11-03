/*
	$ : WA,
	Also tried removing addition of nums[ptr1] & nums[ptr2]
*/

class Solution {
public:

	int maxScore(vector<int>& nums, int ptr1, int ptr2, int& p1, int& p2, int turn) {

		// Base Case
		if (ptr1 == ptr2)
			return nums[ptr1];

		if (ptr1 > ptr2)
			return 0;

		// Recursive

		if (turn == 1) {
			// Select the first
			int first = nums[ptr1] + maxScore(nums, ptr1 + 1, ptr2, p1, p2, 2);

			// Select the last
			int last = nums[ptr2] + maxScore(nums, ptr1, ptr2 - 1, p1, p2, 2);

			// Select the max out of these 2
			p1 += max(first, last);

			return p1;
		}

		// Select the first
		int first = nums[ptr1] + maxScore(nums, ptr1 + 1, ptr2, p1, p2, 1);

		// Select the last
		int last = nums[ptr2] + maxScore(nums, ptr1, ptr2 - 1, p1, p2, 1);

		// Select the max out of these 2
		p2 += max(first, last);

		return p2;

	}

	bool PredictTheWinner(vector<int>& nums) {
		int p1 = 0;
		int p2 = 0;
		//int turn = 1;
		int temp = maxScore(nums, 0, nums.size() - 1, p1, p2, 1);

		cout << "P1 max : " << p1 << endl;
		cout << "P2 max : " << p2 << endl;

		return p1 > p2 ? true : false;
	}
};

/*
	Net soln 1
	$ : AC
*/

class Solution {
public:
	int dfs(vector<int>&nums, int left, int right) {
		//The meaning of DFS here is the difference between the current operation of the player score and the score of another player.
		if (left == right)
			return nums[left];
		return max(nums[left] - dfs(nums, left + 1, right), nums[right] - dfs(nums, left, right - 1));
	}

	//Because "players' gameplay will make his score to maximize, the current player should choose the strategy that is much higher than the other score.
	bool PredictTheWinner(vector<int>& nums) {
		return dfs(nums, 0, nums.size() - 1) >= 0;
		//The difference between its own score and the other party is not less than 0. The score is not less than the score of each other.
	}
};

