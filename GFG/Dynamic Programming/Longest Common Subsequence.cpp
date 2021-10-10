/*
	Even after memoization, it is giving TLE
*/

class Solution
{
public:

	int helper(string s1, string s2, int sizeS1, int sizeS2, vector<vector<int>>& dp) {

		// Base Case
		if (sizeS1 == -1 || sizeS2 == -1)
			return 0;

		if (dp[sizeS1][sizeS2] != -1)
			return dp[sizeS1][sizeS2];

		if (s1[sizeS1] == s2[sizeS2]) {
			dp[sizeS1][sizeS2] = 1 + helper(s1, s2, sizeS1 - 1, sizeS2 - 1, dp);
			return dp[sizeS1][sizeS2] ;
		}

		dp[sizeS1][sizeS2] = max(helper(s1, s2, sizeS1 - 1, sizeS2, dp), helper(s1, s2, sizeS1, sizeS2 - 1, dp));

		return dp[sizeS1][sizeS2];
	}

	//Function to find the length of longest common subsequence in two strings.
	int lcs(int x, int y, string s1, string s2) {
		// your code here

		vector<vector<int>> dp (x, vector<int>(y, -1));

		return helper(s1, s2, x - 1, y - 1, dp);
	}
};

/*
	OA - Top Down
	$ : AC
*/

class Solution
{
public:

	int helper(string s1, string s2, vector<vector<int>>& dp) {

		// Initializing the first row and first column with 0

		for (int i = 0 ; i < dp.size() ; i++) {
			for (int j = 0 ; j < dp[0].size() ; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
			}
		}

		for (int i = 1 ; i < dp.size() ; i++) {
			for (int j = 1 ; j < dp[0].size() ; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[dp.size() - 1][dp[0].size() - 1];
	}

	//Function to find the length of longest common subsequence in two strings.
	int lcs(int x, int y, string s1, string s2) {
		// your code here

		vector<vector<int>> dp (x + 1, vector<int>(y + 1, -1));

		return helper(s1, s2, dp);
	}
};

/*
	When strings are passsed as references, memoization works too
	$ : AC
*/

class Solution
{
public:

	int helper(string& s1, string& s2, int sizeS1, int sizeS2, vector<vector<int>>& dp) {

		// Base Case
		if (sizeS1 == 0 || sizeS2 == 0)
			return 0;

		if (dp[sizeS1][sizeS2] != -1)
			return dp[sizeS1][sizeS2];

		if (s1[sizeS1 - 1] == s2[sizeS2 - 1]) {
			dp[sizeS1][sizeS2] = 1 + helper(s1, s2, sizeS1 - 1, sizeS2 - 1, dp);
			return dp[sizeS1][sizeS2] ;
		}

		dp[sizeS1][sizeS2] = max(helper(s1, s2, sizeS1 - 1, sizeS2, dp), helper(s1, s2, sizeS1, sizeS2 - 1, dp));

		return dp[sizeS1][sizeS2];
	}

	//Function to find the length of longest common subsequence in two strings.
	int lcs(int x, int y, string s1, string s2) {
		// your code here

		vector<vector<int>> dp (x + 1, vector<int>(y + 1, -1));

		return helper(s1, s2, x, y, dp);
	}
};