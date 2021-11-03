/*
	Using similar logic as Parallel Courses
	$ : AC
*/

class Solution {
public:

	bool helper(int& N, vector<vector<int>>& adjList, vector<int>& indegree) {

		queue<int> q;

		// Add all the nodes with indegree 0 to the queue
		for (int i = 0; i < indegree.size() ; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		int count = 0;

		while (!q.empty()) {

			int size = q.size();
			count += size;

			while (size--) {
				int frontNode = q.front();
				q.pop();

				// Visit the neighbours and reduce their indegree by 1
				for (const int& nbr : adjList[frontNode]) {
					indegree[nbr]--;

					// Check if indegree has become 0. If it has, enque it
					if (indegree[nbr] == 0)
						q.push(nbr);
				}
			}
		}

		return count == N;

	}

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
		// Code here

		// Construct an adjacency list and an indegree array
		vector<vector<int>> adjList(N);
		vector<int> indegree(N, 0);
		for (int i = 0 ; i < prerequisites.size() ; i++) {
			adjList[prerequisites[i].first].push_back(prerequisites[i].second);
			indegree[prerequisites[i].second]++;
		}

		return helper(N, adjList, indegree);

	}
};

/*
	Slightly simpler implementation (Since we do not need level)
	$ : AC
*/

class Solution {
public:

	bool helper(int& N, vector<vector<int>>& adjList, vector<int>& indegree) {

		queue<int> q;

		// Add all the nodes with indegree 0 to the queue
		for (int i = 0; i < indegree.size() ; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		int count = q.size();

		while (!q.empty()) {

			int frontNode = q.front();
			q.pop();

			// Visit the neighbours and reduce their indegree by 1
			for (const int& nbr : adjList[frontNode]) {
				indegree[nbr]--;

				// Check if indegree has become 0. If it has, enque it
				if (indegree[nbr] == 0) {
					q.push(nbr);
					count++;
				}
			}
		}

		return count == N;

	}

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
		// Code here

		// Construct an adjacency list and an indegree array
		vector<vector<int>> adjList(N);
		vector<int> indegree(N, 0);
		for (int i = 0 ; i < prerequisites.size() ; i++) {
			adjList[prerequisites[i].first].push_back(prerequisites[i].second);
			indegree[prerequisites[i].second]++;
		}

		return helper(N, adjList, indegree);

	}
};