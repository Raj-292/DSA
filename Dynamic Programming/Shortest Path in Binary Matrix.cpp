/*
	TLE
*/

class Solution {
public:


	void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& n, int cumLength, int& res, int x, int y) {

		// Base Case
		if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
			return;

		if (grid[x][y] == 1 || visited[x][y])
			return;

		if (x == n - 1 && y == n - 1)
			res = min(res, cumLength);

		// Recursive

		// Mark current cell visited
		visited[x][y] = true;

		// Visit all 8 possible directons
		// Top
		helper(grid, visited, n, cumLength + 1, res, x - 1, y);
		// Top-Left
		helper(grid, visited, n, cumLength + 1, res, x - 1, y - 1);
		// Top-Right
		helper(grid, visited, n, cumLength + 1, res, x - 1, y + 1);
		// Bottom
		helper(grid, visited, n, cumLength + 1, res, x + 1, y);
		// Bottom-Left
		helper(grid, visited, n, cumLength + 1, res, x + 1, y - 1);
		// Bottom-Right
		helper(grid, visited, n, cumLength + 1, res, x + 1, y + 1);
		// Left
		helper(grid, visited, n, cumLength + 1, res, x, y - 1);
		// Right
		helper(grid, visited, n, cumLength + 1, res, x, y + 1);

		// Un-Mark current cell visited
		visited[x][y] = false;
	}

	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		int n = grid.size();

		// Visited matrix
		vector<vector<bool>> visited (n, vector<bool>(n, false));

		int res = INT_MAX;

		helper(grid, visited, n, 1, res, 0, 0);

		return res == INT_MAX ? -1 : res;

	}
};

/*
	Added memoization, still TLE
	TLE on test case :
	I/P : [[0,1,0,0,1,1,0],[1,0,0,0,0,0,0],[1,0,0,1,1,1,1],[0,1,0,0,0,0,0],[1,0,0,0,0,0,1],[1,0,0,1,0,0,0],[1,0,1,0,0,1,0]]

*/

class Solution {
public:


	void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& dp, int& n, int cumLength, int& res, int x, int y) {

		// Base Case
		if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
			return;

		if (grid[x][y] == 1 || visited[x][y])
			return;

		if (x == n - 1 && y == n - 1) {
			res = min(res, cumLength);
			dp[x][y] = res;
		}


		// Recursive

		if (dp[x][y] != -1) {
			res = min(res, dp[x][y]);
			return;
		}


		// Mark current cell visited
		visited[x][y] = true;

		// Visit all 8 possible directons
		// Top
		helper(grid, visited, dp, n, cumLength + 1, res, x - 1, y);
		// Top-Left
		helper(grid, visited, dp, n, cumLength + 1, res, x - 1, y - 1);
		// Top-Right
		helper(grid, visited, dp, n, cumLength + 1, res, x - 1, y + 1);
		// Bottom
		helper(grid, visited, dp, n, cumLength + 1, res, x + 1, y);
		// Bottom-Left
		helper(grid, visited, dp, n, cumLength + 1, res, x + 1, y - 1);
		// Bottom-Right
		helper(grid, visited, dp, n, cumLength + 1, res, x + 1, y + 1);
		// Left
		helper(grid, visited, dp, n, cumLength + 1, res, x, y - 1);
		// Right
		helper(grid, visited, dp, n, cumLength + 1, res, x, y + 1);

		// Un-Mark current cell visited
		visited[x][y] = false;
	}

	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		int n = grid.size();

		// Visited matrix
		vector<vector<bool>> visited (n, vector<bool>(n, false));

		// Memoization
		vector<vector<int>> dp (n, vector<int>(n, -1));

		int res = INT_MAX;

		helper(grid, visited, dp, n, 1, res, 0, 0);

		return res == INT_MAX ? -1 : res;

	}
};

/*
	BFS
	$ : AC
*/

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> path(n, vector<int> (m, 0));
		path = grid;

		if (grid[0][0] == 1) return -1;
		path[0][0] = 1;
		queue<pair<int, int>> q;
		q.push({0, 0});
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			if (i == n - 1 && j == m - 1) return path[i][j];

			// Move in all 8 directions
			int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
			int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

			for (int dir = 0 ; dir < 8 ; dir++) {
				int newx = i + dx[dir];
				int newy = j + dy[dir];

				if (newx >= 0 && newx < n && newy >= 0 && newy < n && path[newx][newy] == 0) {
					q.push({newx, newy});
					path[newx][newy] = 1 + path[i][j];
					if (newx == n - 1 && newy == m - 1) return path[newx][newy];
				}

			}
		}
		return -1;
	}
};

