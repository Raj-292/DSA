/*
	$ : 32 / 44 test cases passed.
	I/P : 3,[[1,0],[1,2],[0,1]]
	O/P : [2]
	Exp : []
*/

class Solution {
public:

	vector<int> helper(int& n, vector<vector<int>>& adjList, vector<int>& indegree) {

		vector<int> res;

		queue<int> q;

		// Add the nodes with 0 indegree to the queue & pushing to result vector
		for (int i = 0 ; i < n ; i++) {
			if (!indegree[i]) {
				q.push(i);
				res.push_back(i);
			}
		}

		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();

			// Visiting the neighbours & reducing their indegree
			for (const int& nbr : adjList[frontNode]) {
				indegree[nbr]--;
				// Check if indegree has become 0 & add it if has become 0
				if (!indegree[nbr]) {
					q.push(nbr);
					res.push_back(nbr);
				}
			}
		}

		return res;
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		// Constructing an indegree array
		vector<int> indegree(numCourses, 0);
		for (const vector<int>& vec : prerequisites) {
			indegree[vec[0]]++;
		}

		// Constructing an adjacency list of the graph
		vector<vector<int>> adjList(numCourses);
		for (const vector<int>& vec : prerequisites) {
			adjList[vec[1]].push_back(vec[0]);
		}

		return helper(numCourses, adjList, indegree);

	}
};

/*
	Added a check for the case where there is no possible order to complete all the courses
	$ : AC
*/

class Solution {
public:

	vector<int> helper(int& n, vector<vector<int>>& adjList, vector<int>& indegree) {

		vector<int> res;

		queue<int> q;

		// Add the nodes with 0 indegree to the queue & pushing to result vector
		for (int i = 0 ; i < n ; i++) {
			if (!indegree[i]) {
				q.push(i);
				res.push_back(i);
			}
		}

		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();

			// Visiting the neighbours & reducing their indegree
			for (const int& nbr : adjList[frontNode]) {
				indegree[nbr]--;
				// Check if indegree has become 0 & add it if has become 0
				if (!indegree[nbr]) {
					q.push(nbr);
					res.push_back(nbr);
				}
			}
		}

		// Check to see if all the courses are possible
		if (res.size() != n)
			return {};

		return res;
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		// Constructing an indegree array
		vector<int> indegree(numCourses, 0);
		for (const vector<int>& vec : prerequisites) {
			indegree[vec[0]]++;
		}

		// Constructing an adjacency list of the graph
		vector<vector<int>> adjList(numCourses);
		for (const vector<int>& vec : prerequisites) {
			adjList[vec[1]].push_back(vec[0]);
		}

		return helper(numCourses, adjList, indegree);

	}
};