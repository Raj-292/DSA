/*
	Imp : Start can be any cell of the grid (unlike rat in a maze)
	$ : WA
	I/P : [["a"]] | "a"
	O/P : false
	Exp : true
*/

class Solution {
public:

	bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int& m, int& n, string path, int x, int y) {

		// Base Case
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return false;

		if (visited[x][y])
			return false;

		// Check if path == word
		if (path == word)
			return true;


		// Marking the current cell as visited
		visited[x][y] = true;

		// D L R U
		// Down
		bool downSearch = helper(board, visited, word, m, n, path + board[x][y], x + 1, y);

		// Left
		bool leftSearch = helper(board, visited, word, m, n, path + board[x][y], x, y - 1);

		// Right
		bool rightSearch = helper(board, visited, word, m, n, path + board[x][y], x, y + 1);

		// Up
		bool upSearch = helper(board, visited, word, m, n, path + board[x][y], x - 1, y);

		// Un - Marking the current cell as visited
		visited[x][y] = false;

		// Return true if any of the directions is true
		return downSearch || leftSearch || rightSearch || upSearch;

	}

	bool exist(vector<vector<char>>& board, string word) {

		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> visited (m, vector<bool>(n, false));

		bool res = false;

		// Start can be any grid
		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				res = res || helper(board, visited, word, m, n, "", i, j);
			}
		}

		return res;
	}
};

/*
	Added the check of path == word before other base cases
	$ : Above TC passed but TLE
	I/P : [["b","b","a","a","b","a"],["b","b","a","b","a","a"],["b","b","b","b","b","b"],["a","a","a","b","a","a"],["a","b","a","a","b","b"]] | "abbbababaa"
*/

class Solution {
public:

	bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int& m, int& n, string path, int x, int y) {

		// Check if path == word
		if (path == word)
			return true;

		// Base Case
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return false;

		if (visited[x][y])
			return false;




		// Marking the current cell as visited
		visited[x][y] = true;

		// D L R U
		// Down
		bool downSearch = helper(board, visited, word, m, n, path + board[x][y], x + 1, y);

		// Left
		bool leftSearch = helper(board, visited, word, m, n, path + board[x][y], x, y - 1);

		// Right
		bool rightSearch = helper(board, visited, word, m, n, path + board[x][y], x, y + 1);

		// Up
		bool upSearch = helper(board, visited, word, m, n, path + board[x][y], x - 1, y);

		// Un - Marking the current cell as visited
		visited[x][y] = false;

		// Return true if any of the directions is true
		return downSearch || leftSearch || rightSearch || upSearch;

	}

	bool exist(vector<vector<char>>& board, string word) {

		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> visited (m, vector<bool>(n, false));

		bool res = false;

		// Start can be any grid
		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				res = res || helper(board, visited, word, m, n, "", i, j);
			}
		}

		return res;
	}
};

/*
	Two optimizations : Call helper only if board[i][j] == word[0]
					  : In the base condition, if path.size() becomes greater than word.size(), return false;

	$ : TLE
	I/P : [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]] | "AAAAAAAAAAAAAAB"
*/

class Solution {
public:

	bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int& m, int& n, string path, int x, int y) {

		// Check if path == word
		if (path == word)
			return true;

		// Base Case
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return false;

		if (path.size() > word.size())
			return false;

		if (visited[x][y])
			return false;


		// Marking the current cell as visited
		visited[x][y] = true;

		// D L R U
		// Down
		bool downSearch = helper(board, visited, word, m, n, path + board[x][y], x + 1, y);
		if (downSearch) {
			visited[x][y] = false;
			return true;
		}

		// Left
		bool leftSearch = helper(board, visited, word, m, n, path + board[x][y], x, y - 1);
		if (leftSearch) {
			visited[x][y] = false;
			return true;
		}

		// Right
		bool rightSearch = helper(board, visited, word, m, n, path + board[x][y], x, y + 1);
		if (rightSearch) {
			visited[x][y] = false;
			return true;
		}

		// Up
		bool upSearch = helper(board, visited, word, m, n, path + board[x][y], x - 1, y);
		if (upSearch) {
			visited[x][y] = false;
			return true;
		}

		// Un - Marking the current cell as visited
		visited[x][y] = false;

		// Return true if any of the directions is true
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {

		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> visited (m, vector<bool>(n, false));


		bool res = false;

		// Start can be any grid
		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (board[i][j] == word[0]) {
					res = res || helper(board, visited, word, m, n, "", i, j);
					if (res)
						return true;
				}
			}
		}

		return false;
	}
};

/*
	Changed the validation logic, instead of adding to the path, kept a pos counter which keeps incremeting as it finds letters that match
	$ : AC
*/

class Solution {
public:

	bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int& m, int& n, int pos, int x, int y) {

		// Check if path == word
		if (pos == word.size())
			return true;

		// Base Case
		if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
			return false;

		if (visited[x][y] || board[x][y] != word[pos])
			return false;

		// Marking the current cell as visited
		visited[x][y] = true;

		// D L R U
		// Down
		bool downSearch = helper(board, visited, word, m, n, pos + 1, x + 1, y);
		if (downSearch) {
			visited[x][y] = false;
			return true;
		}

		// Left
		bool leftSearch = helper(board, visited, word, m, n, pos + 1, x, y - 1);
		if (leftSearch) {
			visited[x][y] = false;
			return true;
		}

		// Right
		bool rightSearch = helper(board, visited, word, m, n, pos + 1, x, y + 1);
		if (rightSearch) {
			visited[x][y] = false;
			return true;
		}

		// Up
		bool upSearch = helper(board, visited, word, m, n, pos + 1, x - 1, y);
		if (upSearch) {
			visited[x][y] = false;
			return true;
		}

		// Un - Marking the current cell as visited
		visited[x][y] = false;

		// Return true if any of the directions is true
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {

		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>> visited (m, vector<bool>(n, false));

		bool res = false;

		// Start can be any grid
		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (board[i][j] == word[0]) {
					res = res || helper(board, visited, word, m, n, 0, i, j);
					if (res)
						return true;
				}
			}
		}

		return false;
	}
};