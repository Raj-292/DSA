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