/*
	$ : AC
*/

class Solution {
public:

	int helper(int arr[], vector<vector<int>>& dp, int i, int j) {

		if (dp[i][j] != -1)
			return dp[i][j];

		if (i >= j)
			return 0;

		int res = INT_MAX;

		for (int k = i ; k < j ; k++) {

			int currentRes = helper(arr, dp, i, k) + helper(arr, dp, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
			if (currentRes < res) {
				res = currentRes;
			}

		}

		return dp[i][j] = res;
	}

	int matrixMultiplication(int N, int arr[]) {
		// code here
		vector<vector<int>> dp(101, vector<int>(101, -1));
		return helper(arr, dp, 1, N - 1);
	}
};