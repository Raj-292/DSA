//Question link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

//In mysoln, combining at parent method is used.
bool isValid(int i, int j, vector<vector<int>> &m, int n, bool visited[5][5]) {
	if (i == -1 || i == n || j == -1 || j == n || visited[i][j] || m[i][j] == 0) {
		return false;
	}

	return true;
}

vector<string> getPaths(vector<vector<int>> &m, int n, bool visited[5][5], int i, int j ) {

	vector<string> res;

	//base case
	if (i == -1 || i == n || j == -1 || j == n || visited[i][j] || m[i][j] == 0) {
		return {};
	}

	// reached (n-1,n-1)

	if (i == n - 1 && j == n - 1) {
		return {""};
	}

	// Mainining order D,L,R,U

	vector<string> cd;
	vector<string> cl;
	vector<string> cr;
	vector<string> cu;

	visited[i][j] = true;

	//Down
	if (isValid(i + 1, j, m, n, visited)) {
		cd = getPaths(m, n, visited, i + 1, j);
		//insert 'D' @ start of each vector
		for (int x = 0; x < cd.size(); x++) {
			cd[x].insert(cd[x].begin(), 'D');
		}
	}

	//Left
	if (isValid(i, j - 1, m, n, visited)) {
		cl = getPaths(m, n, visited, i, j - 1);
		//insert 'L' @ start of each vector
		for (int x = 0; x < cl.size(); x++) {
			cl[x].insert(cl[x].begin(), 'L');
		}
	}

	//Right
	if (isValid(i, j + 1, m, n, visited)) {
		cr = getPaths(m, n, visited, i, j + 1);
		//insert 'R' @ start of each vector
		for (int x = 0; x < cr.size(); x++) {
			cr[x].insert(cr[x].begin(), 'R');
		}
	}

	//Up
	if (isValid(i - 1, j, m, n, visited)) {
		cu = getPaths(m, n, visited, i - 1, j);
		//insert 'U' @ start of each vector
		for (int x = 0; x < cu.size(); x++) {
			cu[x].insert(cu[x].begin(), 'U');
		}
	}

	//Combining the results:
	res = cd;

	for (int y = 0; y < cl.size(); y++) {
		res.push_back(cl[y]);
	}

	for (int y = 0; y < cr.size(); y++) {
		res.push_back(cr[y]);
	}

	for (int y = 0; y < cu.size(); y++) {
		res.push_back(cu[y]);
	}

	visited[i][j] = false;

	return res;

}

vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here
	bool visited[5][5];
	memset(visited, false, sizeof(visited));

	vector<string> result = getPaths(m, n, visited, 0, 0);

	return result;
}


//<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\\
