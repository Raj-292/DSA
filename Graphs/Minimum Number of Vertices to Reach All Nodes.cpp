/*
	$ : AC
*/

class Solution {
public:

	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

		// Constructing indegree map
		unordered_map<int, int> mp;

		// Initializing map
		for (int i = 0 ; i < n ; i++) {
			mp[i] = 0;
		}

		for (const vector<int>& vec : edges) {
			mp[vec[1]]++;
		}

		// Result vector.
		vector<int> res;

		// Calculate total nodes with indegree 0
		for (auto x : mp) {
			if (x.second == 0)
				res.push_back(x.first);
		}

		return res;
	}
};