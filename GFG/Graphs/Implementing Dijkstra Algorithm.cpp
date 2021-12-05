// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:

	int getMin(int V, vector<int>& distance, vector<bool>& visited) {
		int minVertex = -1;
		for (int i = 0 ; i < V ; i++) {
			if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
				minVertex = i;
			}
		}

		return minVertex;
	}

	vector<int> helper(int V, vector<vector<int>> adj[], int S) {

		vector<bool> visited(V, false);
		vector<int> distance(V, INT_MAX);

		// Setting the distance of source to be 0
		distance[S] = 0;

		// Visiting the nodes & their neighbours
		for (int i = 0 ; i < V - 1 ; i++) {
			int minVertex = getMin(V, distance, visited);
			// Marking the minVertex visited
			visited[minVertex] = true;

			// Visting the neighbours of minVertex
			for (const vector<int>& x : adj[minVertex]) {
				if (!visited[x[0]]) {
					distance[x[0]] = min(distance[x[0]], distance[minVertex] + x[1]);
				}
			}
		}

		return distance;
	}

	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		// Code here
		return helper(V, adj, S);
	}
};


// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while (t--) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>> adj[V];
		int i = 0;
		while (i++ < E) {
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1, t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}
		int S;
		cin >> S;

		Solution obj;
		vector<int> res = obj.dijkstra(V, adj, S);

		for (int i = 0; i < V; i++)
			cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}

// } Driver Code Ends

/*
	Using priority queue
*/

class Solution
{
private:

	struct custom_cmp {

		bool operator()(pair<int, int> x, pair<int, int> y) {
			return x.second > y.second; // Priority based on edge weight
		}

	};

public:
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {

		// Constructing distance vector
		vector<int> distance(V, INT_MAX);

		// Visited vector
		vector<bool> visited(V, false);

		// Constructing a priority queue.
		priority_queue<pair<int, int>, vector<pair<int, int>>, custom_cmp> pq;

		// Pushing the source node into the priority queue
		pq.push({S, 0});

		while (!pq.empty()) {
			pair<int, int> frontP = pq.top();
			pq.pop();

			if (visited[frontP.first])
				continue;

			visited[frontP.first] = true;

			distance[frontP.first] = frontP.second;

			// Visit the neighbours of frontP and reduce their distance

			for (const vector<int>& nbr : adj[frontP.first]) {
				pq.push({nbr[0], nbr[1] + frontP.second});
			}

		}
		return distance;
	}
};

/*
	In above approach, greater<pair<int,int>> can be used in place of custom_cmp and pair<int,int> can be modified such that weight is first and node is second.
*/