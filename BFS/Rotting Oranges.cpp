/*
	Very similar to Shortest Path in Binary Matrix
	$ : AC
*/

class Solution {
public:

	int helper(vector<vector<int>>& grid, int& m, int& n) {

		queue<pair<pair<int, int>, int>> q; // q[x].first => {x,y} , q[x].second => time

		int totalTime = 0;

		// Add all the rotten ones to the queue with time 0
		for (int i = 0 ; i < m ; i++)
			for (int j = 0 ; j < n ; j++)
				if (grid[i][j] == 2)
					q.push({{i, j}, 0});

		while (!q.empty()) {

			int x = q.front().first.first;
			int y = q.front().first.second;
			int timeToPass = q.front().second;
			totalTime = timeToPass;

			q.pop();

			// Rot 4-adjacent cells => D, L, R, U
			int dx[] = {1, 0, 0, -1};
			int dy[] = {0, -1, 1, 0};

			for (int dir = 0 ; dir < 4 ; dir++) {
				int newX = x + dx[dir];
				int newY = y + dy[dir];

				if (newX >= 0 && newX < m && newY >= 0 && newY < n)
					if (grid[newX][newY] == 1 ) {
						q.push({{newX, newY}, timeToPass + 1});
						grid[newX][newY] = 2;
					}
			}
		}

		//Check if any fresh orange still exists
		for (const vector<int>& row : grid)
			for (const int& orange : row)
				if (orange == 1)
					return -1;

		return totalTime;
	}

	int orangesRotting(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		return helper(grid, m, n);
	}
};