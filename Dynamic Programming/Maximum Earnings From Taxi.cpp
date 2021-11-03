/*
	WIP
*/

class Solution {
public:
	int maxTaxiEarnings(int n, vector<vector<int>>& rides) {

		// Sort acc. to end times, if overlap, select one

		sort(rides.begin(), rides.end(), [ = ], (vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
		});

		int maxEarnings = 0;

		vector<int> prev = rides[0];

		// Check for rest of the rides : 1 ... n-1
		for (int i = 1 ; i < rides.size() ; i++) {
			// No Overlap condition
			if (rides[i][0] > prev[1]) {
				maxEarnings += (rides[i][1] - rides[i][0] + rides[i][2]);
			} else {
				// Overlap condition
				maxEarnings += max((prev[1] - prev[0] + prev[2]), (rides[i][1] - rides[i][0] + rides[i][2]));

			}
		}

	}
};

/*
	DP
	$ : WA
	I/P :  10 | | [[2,3,6],[8,9,8],[5,9,7],[8,9,1],[2,9,2],[9,10,6],[7,10,10],[6,7,9],[4,9,7],[2,3,1]]
	O/P : 25
	Exp : 33
*/

class Solution {
public:

	int helper(int& n, unordered_map<int, vector<int>>& mp, vector<int>& dp, int pickUpPoint) {

		// Base Case.
		if (pickUpPoint >= n)
			return 0;

		if (mp[pickUpPoint].size() == 0)
			return  helper(n, mp, dp, pickUpPoint + 1);

		if (dp[pickUpPoint] != -1)
			return dp[pickUpPoint];

		// Recursive
		// Take
		int take = mp[pickUpPoint][1] - mp[pickUpPoint][0] + mp[pickUpPoint][2] + helper(n, mp, dp, mp[pickUpPoint][1]);
		// Not Take
		int notTake = helper(n, mp, dp, pickUpPoint + 1);

		return dp[pickUpPoint] = max(take, notTake);
	}

	int maxTaxiEarnings(int n, vector<vector<int>>& rides) {

		// mapping start point
		unordered_map<int, vector<int>> mp;

		for (const vector<int>& ride : rides) {
			mp[ride[0]] = {ride[0], ride[1], ride[2]};
		}

		// Dp
		vector<int> dp(100001, -1);

		return helper(n, mp, dp, 0);
	}
};