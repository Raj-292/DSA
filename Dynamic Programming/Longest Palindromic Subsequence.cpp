/*
    $ : AC
*/


class Solution {
public:

    int lcs(string& s1, string& s2, int n, vector<vector<int>>& dp) {

        for (int i = 1 ; i < dp.size() ; i++) {
            for (int j = 1; j < dp[0].size() ; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }


    int longestPalindromeSubseq(string s) {

        int n = s.length();

        vector<vector<int>> dp (n + 1, vector<int>(n + 1, 0));

        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());

        int res = lcs(s, reversedS, n, dp);

        return res;
    }
};