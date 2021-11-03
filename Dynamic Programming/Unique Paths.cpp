/*
	$ : AC
*/

class Solution {
public:


	int helper(int& m, int& n, vector<vector<int>>& dp, int x, int y) {

		// Base Case.
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return 0;

		if (x == m - 1 && y == n - 1)
			return 1;

		if (dp[x][y] != -1)
			return dp[x][y];

		// Recursive
		return dp[x][y] = helper(m, n, dp, x + 1, y) + helper(m, n, dp, x, y + 1);

	}

	int uniquePaths(int m, int n) {

		vector<vector<int>> dp(m, vector<int>(n, -1));

		return helper(m, n, dp, 0, 0);
	}
};