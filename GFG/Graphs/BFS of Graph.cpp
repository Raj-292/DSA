/*
    $ : AC
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:


    vector<int> helper(int V, vector<int> adj[], vector<int>& visited) {

        vector<int> res;

        queue<int> q;
        q.push(0);

        visited[0] = true;

        while (!q.empty()) {
            int frontElt = q.front();
            q.pop();
            res.push_back(frontElt);

            //Going through neighbours
            for (const int& x : adj[frontElt]) {
                if (!visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }

        return res;
    }



    //Function to return Breadth First Traversal of given graph.
    vector<int>bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, false);

        return helper(V, adj, visited);
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
            //      adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends