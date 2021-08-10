/*
	Using Implicit return
	$ : AC
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:

	void helper(vector<int> adj[], vector<bool>& visited, int curr, vector<int>& res) {
		visited[curr] = true;
		res.push_back(curr);
		for (const int& x : adj[curr]) {
			if (!visited[x])
				helper(adj, visited, x, res);
		}
	}


	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[]) {
		// Code here
		vector<bool> visited(V, false);
		vector<int> res;

		helper(adj, visited, 0, res);
		return res;
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

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// string s1;
		// cin>>s1;
		Solution obj;
		vector<int>ans = obj.dfsOfGraph(V, adj);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends

/*
	Using Explicit Return
	$ : AC

*/


class Solution
{
public:

	vector<int> helper(vector<int> adj[], vector<bool>& visited, int curr) {

		//base case
		if (adj[curr].size() == 0) {
			return {curr};
		}


		vector<int> res;

		visited[curr] = true;
		res.push_back(curr);
		for (const int& x : adj[curr]) {
			if (!visited[x]) {
				vector<int> v1 = helper(adj, visited, x);

				for (int i = 0 ; i < v1.size() ; i++) {
					res.push_back(v1[i]);
				}

			}
		}

		return res;
	}


	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[]) {
		// Code here
		vector<bool> visited(V, false);

		vector<int> res = helper(adj, visited, 0);
		return res;
	}
};