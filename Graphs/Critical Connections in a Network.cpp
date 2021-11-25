/*
	$ : WA
	I/P : 6
		 [[0,1],[1,2],[2,0],[1,3],[3,4],[4,5],[5,3]]
	O/P : [[5,4],[4,3],[3,1]]
	Exp : [[1,3]]
*/

class Solution {
public:

	void dfs(vector<vector<int>>& res, vector<vector<int>> adjList, vector<bool>& visited, vector<int>& dt, vector<int>& lt, int& totalTime, int currNode, int parent ) {

		// Mark the current total Time as discovery time
		dt[currNode] = totalTime;
		totalTime++;
		visited[currNode] = true;

		// Go through the neighbours
		for (const int& nbr : adjList[currNode]) {
			if (!visited[nbr]) {
				dfs(res, adjList, visited, dt, lt, totalTime, nbr, currNode);
			}
		}

		// While returning to caller, select the lowest lt amongst the neighbours except parent

		for (const int& nbr : adjList[currNode])
			if (nbr != parent)
				lt[currNode] = min(lt[currNode], lt[nbr]);

		// If lt[currNode] is greater than dt[parent] then bridge exists

		if (parent != -1)
			if (lt[currNode] > dt[parent])
				res.push_back({currNode, parent});

	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

		// Adjacency List
		vector<vector<int>> adjList(n);
		for (const vector<int>& v : connections) {
			adjList[v[0]].push_back(v[1]);
			adjList[v[1]].push_back(v[0]);
		}

		// Res
		vector<vector<int>> res;

		// Visited
		vector<bool> visited(n, false);

		// Discovery Time
		vector<int> dt(n, INT_MAX);

		// Low time
		vector<int> lt(n, INT_MAX);

		// Parent
		vector<int> parent(n, -1);

		// Selecting node 0 as the source node
		//dt[0] = 1;
		lt[0] = 1;
		int totalTime = 1;

		dfs(res, adjList, visited, dt, lt, totalTime, 0, -1);

		return res;
	}
};