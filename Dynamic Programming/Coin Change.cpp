/* Address Sanitizer Deadly Signal


*/


class Solution {
public:

    int helper(vector<int>& coins, int amount, int idx) {

        //base case
        if (idx == coins.size())
            return INT_MAX - 999999;

        if (amount == 0)
            return 1;

        //recursive

        return min(1 + helper(coins, amount - coins[idx], idx), helper(coins, amount, idx + 1));

    }


    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount, 0);
    }
};

/*
    Address Sanitizer error gone, WA
    instead of if (idx == coins.size()),
    do if (idx == coins.size() || amount < 0)

    $: Wherever -1 is expected, INT_MAX is being thrown.
       Elsewhere, O/P is 1 more than expected

*/

class Solution {
public:

    int helper(vector<int>& coins, int amount, int idx) {

        //base case
        if (idx == coins.size() || amount < 0)
            return INT_MAX - 999999;

        if (amount == 0)
            return 1;

        //recursive

        return min(1 + helper(coins, amount - coins[idx], idx), helper(coins, amount, idx + 1));

    }


    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount, 0);
    }
};

/*
    Jugaad
    $ : Passes all example TCs
      : TLE on submit

*/

class Solution {
public:

    int helper(vector<int>& coins, int amount, int idx) {

        //base case
        if (idx == coins.size() || amount < 0)
            return INT_MAX - 999999;

        if (amount == 0)
            return 1;

        //recursive

        //take
        int take = 1 + helper(coins, amount - coins[idx], idx);

        //not take
        int notTake = helper(coins, amount, idx + 1);

        return min(1 + helper(coins, amount - coins[idx], idx), helper(coins, amount, idx + 1));

    }


    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount, 0);

        return res == INT_MAX - 999999 ? -1 : res - 1 ;
    }
};

/*
    Using memoization
    $ : AC , 112ms , 45.5MB

*/


class Solution {
public:

    int helper(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {

        //base case
        if (idx == coins.size() || amount < 0)
            return INT_MAX - 999999;

        if (amount == 0)
            return 1;

        //recursive

        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int res = min(1 + helper(coins, amount - coins[idx], idx, dp), helper(coins, amount, idx + 1, dp));

        dp[idx][amount] = res;

        return res;

    }


    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp (n, vector<int>(amount + 1, -1));


        int res = helper(coins, amount, 0, dp);

        return res == INT_MAX - 999999 ? -1 : res - 1 ;
    }
};
