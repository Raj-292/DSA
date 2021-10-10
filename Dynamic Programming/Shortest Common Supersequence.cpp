/*
    Similar to Print LCS
    $ : AC
*/

class Solution {
public:

    string printSCS(string& str1, string& str2, vector<vector<int>>& dp) {

        vector<char> res;

        int i = dp.size() - 1;
        int j = dp[0].size() - 1;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                res.push_back(str1[i - 1]);
                i--;
            } else {
                res.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            res.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            res.push_back(str2[j - 1]);
            j--;
        }


        reverse(res.begin(), res.end());
        string resString(res.begin(), res.end());

        return resString;
    }

    string helper(string& str1, string& str2) {

        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1 ; i < m + 1 ; i++) {
            for (int j = 1 ; j < n + 1 ; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j]  = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return printSCS(str1, str2, dp);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return helper(str1, str2);
    }
};