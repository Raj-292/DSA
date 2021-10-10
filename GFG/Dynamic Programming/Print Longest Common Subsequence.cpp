#include<bits/stdc++.h>
using namespace std;

int helper(string s1, string s2, vector<vector<int>>& dp) {

	stack<char> res;
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

	int i = dp.size() - 1; // Basically, m = dp.size()-1
	int j = dp[0].size() - 1; //  n = dp[0].size()-1

	while (i != 0 && j != 0) {
		if (s1[i - 1] == s2[j - 1]) {
			res.push(s1[i - 1]);
			i--;
			j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	while (!res.empty()) {
		cout << res.top() << "  ";
		res.pop();
	}


	return dp[dp.size() - 1][dp[0].size() - 1];
}

//Function to find the length of longest common subsequence in two strings.
int main() {
	// your code here

	string s1 = "acbcf";
	string s2 = "abcdaf";

	int x = 5;
	int y = 6;

	vector<vector<int>> dp (x + 1, vector<int>(y + 1, -1));

	int res =  helper(s1, s2, dp);
	cout << "Res : " << res;
}