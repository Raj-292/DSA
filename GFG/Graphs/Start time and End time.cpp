/*
	For Kosaraju's algo, we need to store start time and end times of dfs

	Sample Input used :
	5
	5
	0 1
	1 2
	2 0
	1 3
	3 4

	Output :
	For Node: 0 => Start time: 3 , End time: 4
	For Node: 1 => Start time: 1 , End time: 10
	For Node: 2 => Start time: 2 , End time: 5
	For Node: 3 => Start time: 6 , End time: 9
	For Node: 4 => Start time: 7 , End time: 8
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<pair<int, int>>& times, int& totalTime, int currNode) {

	visited[currNode] = true;
	// Start Time
	times[currNode].first = totalTime;
	totalTime++;

	// Call dfs on neighbours
	for (const int& nbr : adjList[currNode]) {
		if (!visited[nbr]) {
			dfs(adjList, visited, times, totalTime, nbr);
		}
	}

	// End time
	times[currNode].second = totalTime;
	totalTime++;

	return;
}

int main() {
	// your code goes here

	int n; cin >> n;
	int e; cin >> e;

	vector<vector<int>> adjList(n);
	for (int i = 0 ; i < e ; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
	}

	vector<bool> visited (n, false);
	vector<pair<int, int>> times (n);

	int totalTime = 1;

	// Call on 1
	dfs(adjList, visited, times, totalTime, 1);

	// Call on rest
	for (int i = 0 ; i < n ; i++) {
		if (!visited[i])
			dfs(adjList, visited, times, totalTime, i);
	}

	// Print the times array
	for (int i = 0 ; i < n ; i++) {
		cout << "For Node: " << i << " => Start time: " << times[i].first << " , End time: " << times[i].second << '\n';
	}

	return 0;
}


/*
	2 more TC passed,
	$ : TLE
*/

class Solution {
public:

	void dfs(vector<vector<int>>& res, vector<vector<int>> adjList, vector<bool>& visited, vector<int>& dt, vector<int>& lt, int& totalTime, int currNode, int parent ) {

		// Mark the current total Time as discovery time
		dt[currNode] = totalTime;
		lt[currNode] = totalTime;
		totalTime++;
		visited[currNode] = true;

		// Go through the neighbours
		for (const int& nbr : adjList[currNode]) {
			if (!visited[nbr]) {
				dfs(res, adjList, visited, dt, lt, totalTime, nbr, currNode);
			}
		}

		// Set lt and increment totalTime
		//lt[currNode] = totalTime;
		totalTime++;

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
