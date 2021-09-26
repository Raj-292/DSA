/*
	$ : 166 / 181 test cases passed.
	I/P : ["a!=a"]
	O/P : true
	Exp : false
*/

class Solution {
public:

	void helperDFS(unordered_map<char, vector<char>>& adjList, vector<int>& visited, char source, int label) {

		visited[source] = label;

		// Go through the neighbours
		for (const char& nbr : adjList[source]) {
			if (!visited[nbr]) {
				helperDFS(adjList, visited, nbr, label);
			}
		}

	}

	bool equationsPossible(vector<string>& equations) {

		// Constructing an adjacency list
		unordered_map<char, vector<char>> adjList;

		for (const string& s : equations) {
			if (s[1] == '=') {
				adjList[s[0]].push_back(s[3]);
				adjList[s[3]].push_back(s[0]);
			}
		}

		// Construcing a visited array
		vector<int> visited(1000, 0);

		int label = 1;

		for (auto x : adjList) {
			if (!visited[x.first]) {
				helperDFS(adjList, visited, x.first, label);
				label++;
			}
		}

		// Checking for the inequalities
		for (const string& s : equations) {
			if (s[1] == '!') {
				if (visited[s[0]] == visited[s[3]] && visited[s[0]] != 0 )
					return false;
			}
		}

		return true;
	}
};

/*
	Added a check for cases like a!=a & b!=b
	$ : AC
*/

class Solution {
public:

	void helperDFS(unordered_map<char, vector<char>>& adjList, vector<int>& visited, char source, int label) {

		visited[source] = label;

		// Go through the neighbours
		for (const char& nbr : adjList[source]) {
			if (!visited[nbr]) {
				helperDFS(adjList, visited, nbr, label);
			}
		}
	}

	bool equationsPossible(vector<string>& equations) {

		// Constructing an adjacency list
		unordered_map<char, vector<char>> adjList;

		for (const string& s : equations) {
			if (s[1] == '=') {
				adjList[s[0]].push_back(s[3]);
				adjList[s[3]].push_back(s[0]);
			}
		}

		// Construcing a visited array
		vector<int> visited(1000, 0);

		int label = 1;

		for (auto x : adjList) {
			if (!visited[x.first]) {
				helperDFS(adjList, visited, x.first, label);
				label++;
			}
		}

		// Checking for the inequalities
		for (const string& s : equations) {
			if (s[1] == '!') {
				if (visited[s[0]] == visited[s[3]] && visited[s[0]] != 0 )
					return false;
				if (s[0] == s[3])
					return false;
			}

		}

		return true;
	}
};

