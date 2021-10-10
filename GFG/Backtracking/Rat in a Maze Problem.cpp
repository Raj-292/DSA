/*
	$: WA
*/

class Solution {
public:

	vector<string> helper(vector<vector<int>> & m, vector<vector<bool>>& visited, int& n, int x, int y) {

		// Base Case
		if (x == n - 1 && y == n - 1) {
			return {""};
		}

		if (x < 0 || x > n - 1 || y < 0 ||  y > n - 1) {
			return {};
		}

		if (m[x][y] == 0 || visited[x][y]) {
			return {};
		}

		// Marking current cell as visited
		visited[x][y] = true;

		// Sorted order will be D L R U.

		// Down.
		vector<string> downPath = helper(m, visited, n, x, y + 1);
		//Append 'D' to all the strings in this vector
		for (string& s : downPath) {
			s = "D" + s;
		}

		// Left.
		vector<string> leftPath = helper(m, visited, n, x - 1, y);
		//Append 'L' to all the strings in this vector
		for (string& s : leftPath) {
			s = "L" + s;
		}

		// Right.
		vector<string> rightPath = helper(m, visited, n, x + 1, y);
		//Append 'R' to all the strings in this vector
		for (string& s : rightPath) {
			s = "R" + s;
		}

		// Up.
		vector<string> upPath = helper(m, visited, n, x, y - 1);
		//Append 'U' to all the strings in this vector
		for (string& s : upPath) {
			s = "U" + s;
		}

		// Result would be combining all these vectors
		vector<string> res;
		for (const string& s : downPath) {
			res.push_back(s);
		}

		for (const string& s : leftPath) {
			res.push_back(s);
		}

		for (const string& s : rightPath) {
			res.push_back(s);
		}

		for (const string& s : upPath) {
			res.push_back(s);
		}


		// Unmarking current cell as visited
		visited[x][y] = false;

		return res;
	}

	vector<string> findPath(vector<vector<int>> &m, int n) {
		// Your code goes here
		vector<vector<bool>> visited (n, vector<bool>(n, false));
		vector<string> res = helper(m, visited, n, 0, 0);
		return res;
	}
};

/*
	x and y were interchanged for directions
	$ : AC
*/

class Solution {
public:

	vector<string> helper(vector<vector<int>> & m, vector<vector<bool>>& visited, int& n, int x, int y) {

		// Base Case

		if (x < 0 || x > n - 1 || y < 0 ||  y > n - 1) {
			return {};
		}

		if (m[x][y] == 0 || visited[x][y]) {
			return {};
		}

		if (x == n - 1 && y == n - 1) {
			return {""};
		}


		// Marking current cell as visited
		visited[x][y] = true;

		// Sorted order will be D L R U.

		// Down.
		vector<string> downPath = helper(m, visited, n, x + 1, y);
		//Append 'D' to all the strings in this vector

		for (string& s : downPath) {
			s = "D" + s;
		}


		// Left.
		vector<string> leftPath = helper(m, visited, n, x, y - 1);
		//Append 'L' to all the strings in this vector

		for (string& s : leftPath) {
			s = "L" + s;
		}


		// Right.
		vector<string> rightPath = helper(m, visited, n, x, y + 1);
		//Append 'R' to all the strings in this vector

		for (string& s : rightPath) {
			s = "R" + s;
		}


		// Up.
		vector<string> upPath = helper(m, visited, n, x - 1, y);
		//Append 'U' to all the strings in this vector

		for (string& s : upPath) {
			s = "U" + s;
		}


		// Result would be combining all these vectors
		vector<string> res;
		for (const string& s : downPath) {
			res.push_back(s);

		}

		for (const string& s : leftPath) {
			res.push_back(s);
		}

		for (const string& s : rightPath) {
			res.push_back(s);
		}

		for (const string& s : upPath) {
			res.push_back(s);
		}


		// Unmarking current cell as visited
		visited[x][y] = false;


		return res;
	}

	vector<string> findPath(vector<vector<int>> &m, int n) {
		// Your code goes here
		vector<vector<bool>> visited (n, vector<bool>(n, false));
		vector<string> res = helper(m, visited, n, 0, 0);
		return res;
	}
};

/*
	Implicit Return
	$ : AC
*/

class Solution {
public:

	void helper(vector<vector<int>> &m, vector<vector<bool>>& visited, vector<string>& res, string path, int n, int x, int y) {

		// Base Case
		if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
			return;

		if (m[x][y] == 0 || visited[x][y])
			return;

		// Reached n-1, n-1
		if (x == n - 1 && y == n - 1) {
			res.push_back(path);
			return;
		}

		// Lexicographicaly, order is D L R U

		// Marking the current cell as visited
		visited[x][y] = true;

		// Down
		helper(m, visited, res, path + "D", n, x + 1, y);

		// Left
		helper(m, visited, res, path + "L", n, x, y - 1);

		// Right
		helper(m, visited, res, path + "R", n, x, y + 1);

		// Up
		helper(m, visited, res, path + "U", n, x - 1, y);

		// Un-Marking the current cell as visited
		visited[x][y] = false;


	}

	vector<string> findPath(vector<vector<int>> &m, int n) {
		// Your code goes here
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		vector<string> res;
		helper(m, visited, res, "", n, 0, 0);
		return res;
	}
};