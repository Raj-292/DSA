/*
	WA  for :
	I/P : 1 7 | D | IVSINOK
	O/P : INT_MIN
	Exp : 0
*/

class Solution {
public:

	int helper(string& S1, string& S2, vector<vector<int>>& dp) {

		// No need to initialize first row and col to 0 since whole matrix is already set to 0

		int res = INT_MIN;

		for (int i = 1 ; i < dp.size() ; i++) {
			for (int j = 1 ; j < dp[0].size() ; j++) {
				if (S1[i - 1] == S2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
					res = max(res, dp[i][j]);
				}

				else
					dp[i][j] = 0;
			}
		}

		return res;
	}

	int longestCommonSubstr(string S1, string S2, int n, int m) {
		// your code here

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		return helper(S1, S2, dp);
	}
};

/*
	Added check for final res == INT_MIN
	$ : AC
*/

class Solution {
public:

	int helper(string& S1, string& S2, vector<vector<int>>& dp) {

		// No need to initialize first row and col to 0 since whole matrix is already set to 0

		int res = INT_MIN;

		for (int i = 1 ; i < dp.size() ; i++) {
			for (int j = 1 ; j < dp[0].size() ; j++) {
				if (S1[i - 1] == S2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
					res = max(res, dp[i][j]);
				}

				else
					dp[i][j] = 0;
			}
		}

		return res == INT_MIN ? 0 : res;
	}

	int longestCommonSubstr(string S1, string S2, int n, int m) {
		// your code here

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		return helper(S1, S2, dp);
	}
};