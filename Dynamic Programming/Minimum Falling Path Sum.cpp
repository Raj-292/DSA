/*

class Solution {
public:

    bool isValid(vector<vector<int>>& matrix, int x, int y) {



        if (x < matrix.size() && y < matrix[0].size() && y >= 0)
            return true;

        cout << "inValid x & y :" << x << "  " << y << endl;

        return false;

    }


    long int helper(vector<vector<int>>& matrix, int x, int y) {
        //base case
        if (x == matrix.size() || y < 0 || y == matrix[0].size())
            return 0;

        //recursive

        //consider all 3 possibilites
        // incase any one of them is invalid, we will set them to INT_MAX to avoid errors
        long int diagLeft = INT_MAX;
        long int below = INT_MAX;
        long int diagRight = INT_MAX;

        //if(isValid(matrix,x+1,y-1))
        diagLeft = matrix[x][y] + helper(matrix, x + 1, y - 1);

        //if(isValid(matrix,x+1,y))
        below = matrix[x][y] + helper(matrix, x + 1, y);

        //if(isValid(matrix,x+1,y+1))
        diagRight = matrix[x][y] + helper(matrix, x + 1, y + 1);

        cout << "Min for x: " << x << " and y: " << y << " is: " << min({diagLeft, below, diagRight}) << endl;

        return min({diagLeft, below, diagRight});


    }

    long int minFallingPathSum(vector<vector<int>>& matrix) {
        return helper(matrix, 0, 0);
    }
};

// Thought -> instead of adding in each block, add while returning
// $$ Return 0 only if it reaches bottom


class Solution {
public:

    bool isValid(vector<vector<int>>& matrix, int x, int y) {



        if (x < matrix.size() && y < matrix[0].size() && y >= 0)
            return true;

        cout << "inValid x & y :" << x << "  " << y << endl;

        return false;

    }


    long int helper(vector<vector<int>>& matrix, int x, int y) {
        //base case
        if (x == matrix.size())
            return 0;
        if (y < 0 || y >= matrix.size() || x > matrix.size())
            return INT_MAX;


        //recursive

        //consider all 3 possibilites
        // incase any one of them is invalid, we will set them to INT_MAX to avoid errors
        long int diagLeft = INT_MAX;
        long int below = INT_MAX;
        long int diagRight = INT_MAX;

        // if(isValid(matrix,x+1,y-1))
        diagLeft = helper(matrix, x + 1, y - 1);

        // if(isValid(matrix,x+1,y))
        below = helper(matrix, x + 1, y);

        // if(isValid(matrix,x+1,y+1))
        diagRight = helper(matrix, x + 1, y + 1);

        cout << "Min for x: " << x << " and y: " << y << " is: " << matrix[x][y] + min({diagLeft, below, diagRight}) << endl;

        return matrix[x][y] + min({diagLeft, below, diagRight});

    }

    long int minFallingPathSum(vector<vector<int>>& matrix) {
        long int res = INT_MAX;
        for (int i = 0 ; i < matrix[0].size() ; i++) {
            res = min(res, helper(matrix, 0, i));
        }

        return res;
    }
};

// Example testcases Work - non DP


class Solution {
public:

    bool isValid(vector<vector<int>>& matrix, int x, int y) {


        if (x < matrix.size() && y < matrix[0].size() && y >= 0)
            return true;

        cout << "inValid x & y :" << x << "  " << y << endl;

        return false;

    }


    long int helper(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp) {
        //base case
        if (x == matrix.size())
            return 0;
        if (y < 0 || y >= matrix.size() || x > matrix.size())
            return INT_MAX;


        //recursive

        //consider all 3 possibilites
        // incase any one of them is invalid, we will set them to INT_MAX to avoid errors

        if (dp[x][y] == -1) {

            long int diagLeft = INT_MAX;
            long int below = INT_MAX;
            long int diagRight = INT_MAX;


            // if(isValid(matrix,x+1,y-1))
            diagLeft = helper(matrix, x + 1, y - 1, dp);

            // if(isValid(matrix,x+1,y))
            below = helper(matrix, x + 1, y, dp);

            // if(isValid(matrix,x+1,y+1))
            diagRight = helper(matrix, x + 1, y + 1, dp);

            dp[x][y] = matrix[x][y] + min({diagLeft, below, diagRight});

            return dp[x][y];

        }

        return dp[x][y];

    }

    long int minFallingPathSum(vector<vector<int>>& matrix) {
        long int res = INT_MAX;

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0 ; i < matrix[0].size() ; i++) {
            res = min(res, helper(matrix, 0, i, dp));
        }

        return res;
    }
};

*/

// Attempt on bottom up cleaner approach (Using precomputation)



class Solution {

public:


    //int helper(vector<vector<int>>& matrix, )


    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp (n + 1, vector<int>(n + 2, -1));

        cout << dp.size() << " " << dp[0].size() << endl;

        // intialize last row with zeroes

        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[n][i] = 0;
        }

        // initialize first & last row with INT_MAX

        // for (int i = 0 ; i < dp.size() ; i++) {
        //     dp[0][i] = INT_MAX;
        //     dp[n + 1][i] = INT_MAX;
        // }

        cout << dp.size() << " " << dp[0].size() << endl;

        // for(int i = 0 ; i < dp.size() ; i++) {
        //     for (int j = 0 ; j < dp[0].size() ; j++) {
        //         cout<<dp[i][j]<<"   ";
        //         if(j==dp[0].size()-1)
        //             cout<<'\n';
        //     }
        // }


        // for (int i = n - 1 ; i >= 0 ; i-- ) {
        //     for (int j = 1 ; j <= n ; j++) {
        //         dp[i][j] = matrix[i][j-1] + min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
        //     }
        // }


        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ; j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }



        return 0;

    }
};

/* Some error in INT_MAX block ==> {

    for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = INT_MAX;
            dp[i][n+1] = INT_MAX;
        }
}

    This is the corrected initialization
*/


/* Working :

class Solution {

public:


    //int helper(vector<vector<int>>& matrix, )


    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp (n + 1, vector<int>(n + 2, -1));

        cout << dp.size() << " " << dp[0].size() << endl;

        // intialize last row with zeroes

        for (int i = 0 ; i < dp[0].size() ; i++) {
            dp[n][i] = 0;
        }

        // initialize first & last row with INT_MAX

        for (int i = 0 ; i < dp.size() ; i++) {
            dp[i][0] = INT_MAX;
            dp[i][n + 1] = INT_MAX;
        }

        cout << dp.size() << " " << dp[0].size() << endl;

        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ; j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }


        for (int i = n - 1 ; i >= 0 ; i-- ) {
            for (int j = 1 ; j <= n ; j++) {
                dp[i][j] = matrix[i][j - 1] + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
            }
        }


        for (int i = 0 ; i < dp.size() ; i++) {
            for (int j = 0 ; j < dp[0].size() ; j++) {
                cout << dp[i][j] << "   ";
                if (j == dp[0].size() - 1)
                    cout << '\n';
            }
        }

        int res = INT_MAX;

        for (int i = 0 ; i < dp[0].size() - 1 ; i++) {
            res = min (res, dp[0][i]);
        }



        return res;

    }
};

*/

// Final Cleaned up :

class Solution {

public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp (n + 1, vector<int>(n + 2, -1));

        // intialize last row with zeroes
        for (int i = 0 ; i < n + 2 ; i++) {
            dp[n][i] = 0;
        }

        // initialize first & last column with INT_MAX
        for (int i = 0 ; i < n + 1 ; i++) {
            dp[i][0] = INT_MAX;
            dp[i][n + 1] = INT_MAX;
        }

        for (int i = n - 1 ; i >= 0 ; i-- ) {
            for (int j = 1 ; j <= n ; j++) {
                dp[i][j] = matrix[i][j - 1] + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
            }
        }

        int res = INT_MAX;

        for (int i = 1 ; i < n + 1 ; i++) {
            res = min (res, dp[0][i]);
        }

        return res;
    }
};






