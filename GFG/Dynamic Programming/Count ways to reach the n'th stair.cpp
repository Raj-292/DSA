/*
	Make sure to mod at every possible place where the value might overflow
	$ : AC
*/

class Solution
{
public:

	long long helper(int& n, vector<long long>& dp, int currStep) {

		// Base Case
		if (currStep == n)
			return 1;

		if (currStep > n)
			return 0;

		if (dp[currStep] != -1)
			return dp[currStep];

		// Recursive
		return dp[currStep] = helper(n, dp, currStep + 1) % 1000000007 + helper(n, dp, currStep + 2) % 1000000007;

	}

	//Function to count number of ways to reach the nth stair.
	int countWays(int n) {
		// your code here
		vector<long long> dp(n, -1);

		return int(helper(n, dp, 0) % 1000000007);
	}
};

/*
	Since we are modding, int will also work
	$ : AC
*/

class Solution
{
public:

	long long helper(int& n, vector<long long>& dp, int currStep) {

		// Base Case
		if (currStep == n)
			return 1;

		if (currStep > n)
			return 0;

		if (dp[currStep] != -1)
			return dp[currStep];

		// Recursive
		return dp[currStep] = helper(n, dp, currStep + 1) % 1000000007 + helper(n, dp, currStep + 2) % 1000000007;

	}

	//Function to count number of ways to reach the nth stair.
	int countWays(int n) {
		// your code here
		vector<long long> dp(n, -1);

		return int(helper(n, dp, 0) % 1000000007);
	}
};