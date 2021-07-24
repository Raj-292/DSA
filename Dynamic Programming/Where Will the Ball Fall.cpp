//Initial thoughts -> keep reducing the matrix based on the direction of fall
// if grid[i][j] == 1 -> next recursion call on grid[i+1][j+1]
// if grid[i][j] == -1 -> next recursion call on grid[i+1][j-1]

//stuck conditon -> grid[i][j] == 1 && grid[i][j+1] == -1 or
//				    grid[i][j] == -1 && grid[i][j-1] == 1
// 					grid[i][j] == -1 && j == 0
//  				grid[i][j] == 1 && j == n-1


// base case -> when i reaches m && the stuck cases


class Solution {
public:

	bool isStuck(vector<vector<int>>& grid, int x, int y) {

		if (x == 0 && y == 0 && grid[x][y] == -1)
			return true;
		if (x == grid[0].size() && y == 0 && grid[x][y] == 1)
			return true;
		if (grid[x][y] == 1 && grid[x][y + 1] == -1)
			return true;
		if (grid[x][y] == -1 && grid[x][y - 1] == 1)
			return true;

		return false;
	}

	void helper(vector<vector<int>>& grid, int x, int y, int start, vector<int>& res) {
		//base case

		if (x == grid.size())
			res[start] = y;

		if (isStuck(grid, x, y))
			res[start] = -1;

		//recursive case


		if (grid[x][y] == 1)
			helper(grid, x, y + 1, start, res);
		else
			helper(grid, x, y - 1, start, res);



	}

	vector<int> findBall(vector<vector<int>>& grid) {
		vector<int>res(grid[0].size(), 0);

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));

		for (int i = 0; i < grid[0].size() ; i++) {
			helper(grid, 0, i, i, res);
		}

		return res;
	}
};

// Giving TLE
