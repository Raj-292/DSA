/*
	Using BFS
	$ : AC
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

	bool bfs(int V, vector<int> adj[], vector<bool>& visited, int source) {

		// first is the node itself & second is parent
		queue<pair<int, int>> q;
		q.push({source, -1});
		visited[source] = true;

		while (!q.empty()) {
			pair<int, int> frontElt = q.front();
			q.pop();

			for (const int& x : adj[frontElt.first]) {
				if (!visited[x]) {
					q.push({x, frontElt.first});
					visited[x] = true;
				} else if (x != frontElt.second) {
					return true;
				}
			}

		}

		return false;

	}


	// Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int> adj[]) {
		// Code here
		vector<bool> visited(V, false);

		for (int i = 0 ; i < V ; i++) {
			if (!visited[i]) {
				if (bfs(V, adj, visited, i)) {
					return true;
				}
			}
		}

		return false;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int> adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends

