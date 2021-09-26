/*
	$ : AC
*/

class Solution {
public:

	void helperDFS(int n, vector<vector<int>>& adjList, vector<bool>& visited, int start) {

		// Marking the start as visited
		visited[start] = true;

		// Going through the neighbours of start
		for (const int& x : adjList[start]) {
			if (!visited[x]) {
				helperDFS(n, adjList, visited, x);
			}
		}

		return;
	}

	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {

		// Visited Array.
		vector<bool> visited(n, false);

		// Constructing an adjacency list
		vector<vector<int>> adjList(n);
		for (int i = 0; i < edges.size(); i++) {
			adjList[edges[i][0]].push_back(edges[i][1]);
			adjList[edges[i][1]].push_back(edges[i][0]);
		}

		helperDFS(n, adjList, visited, start);

		// Check visited[end]
		return visited[end];
	}
};