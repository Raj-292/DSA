/*
	No need of memoization
	$ : AC
*/

class Solution {
public:

	int helper(int& m, int& n, vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& totalEmpty, int count) {

		// Base Case.
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return 0;

		if (grid[x][y] == -1 || visited[x][y])
			return 0;

		if (grid[x][y] == 2) {
			return count == totalEmpty + 1 ? 1 : 0;
		}

		// Recursive

		// Mark current cell visited
		visited[x][y] = true;

		int down = helper(m, n, grid, visited, x + 1, y, totalEmpty, count + 1);
		int left = helper(m, n, grid, visited, x, y - 1, totalEmpty, count + 1);
		int right = helper(m, n, grid, visited, x, y + 1, totalEmpty, count + 1);
		int up = helper(m, n, grid, visited, x - 1, y, totalEmpty, count + 1);

		// Un - Mark current cell visited
		visited[x][y] = false;

		return down + left + right + up;
	}


	int uniquePathsIII(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<bool>> visited(m, vector<bool>(n, false));

		int totalEmpty = 0;

		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (grid[i][j] == 0)
					totalEmpty++;
			}
		}

		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (grid[i][j] == 1)
					return helper(m, n, grid, visited, i, j, totalEmpty, 0);
			}
		}

		return 0;
	}
};