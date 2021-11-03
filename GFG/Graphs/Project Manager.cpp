/*
	$ : WA
	I/P : 4 3
		  6 3 6 2
		  0 2
		  1 2
		  0 3
	O/P : 9
	Exp : 12
*/

class Solution {
public:

	int helper(vector<vector<int>>& adjList, vector<int>& indegree, int duration[], int n) {

		int res = 0;

		vector<int> times(n);

		queue<int> q;
		// Adding indegree 0 modules to the queue
		for (int i = 0 ; i < indegree.size() ; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				times[i] = duration[i];
			}
		}

		int count = 0;

		while (!q.empty()) {

			int size = q.size();
			count += size;
			int maxForLevel = INT_MIN;
			while (size--) {
				int frontNode = q.front();
				q.pop();
				maxForLevel = max(maxForLevel, duration[frontNode]);

				// Visiting the neighbours and decrementing their indegree by 1
				for (const int& nbr : adjList[frontNode]) {
					indegree[nbr]--;
					times[nbr] = duration[nbr] + times[frontNode];
					// Check if indegree has become zero, if it has enque it
					if (indegree[nbr] == 0) {
						q.push(nbr);
					}
				}
			}
			// cout << "Adding : " << maxForLevel << endl;
			// res+=maxForLevel;

		}

		//cout << "times : \n";
		for (int i = 0; i < times.size() ; i++) {
			res = max(res, times[i]);
		}

		return count == n ? res : -1;
	}

	int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
		// 	Write your code here

		// Constructing adjacency list and indegree vector
		vector<vector<int>> adjList(n);
		vector<int> indegree(n, 0);
		for (const pair<int, int>& pr : dependency) {
			adjList[pr.first].push_back(pr.second);
			indegree[pr.second]++;
		}

		int minTime = 0;

		return helper(adjList, indegree, duration, n);
	}
};

/*
	$ : AC
*/

class Solution {
public:

	int helper(vector<vector<int>>& adjList, vector<int>& indegree, int duration[], int n) {

		int res = 0;

		vector<int> times(n);

		// Initializing the times array
		for (int i = 0 ; i < times.size() ; i++) {
			times[i] = duration[i];
		}

		queue<int> q;
		// Adding indegree 0 modules to the queue
		for (int i = 0 ; i < indegree.size() ; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				//times[i] = duration[i];
			}
		}

		int count = 0;

		while (!q.empty()) {

			int size = q.size();
			count += size;
			int maxForLevel = INT_MIN;
			while (size--) {
				int frontNode = q.front();
				q.pop();
				maxForLevel = max(maxForLevel, duration[frontNode]);

				// Visiting the neighbours and decrementing their indegree by 1
				for (const int& nbr : adjList[frontNode]) {
					indegree[nbr]--;
					times[nbr] = max(times[nbr], times[frontNode] + duration[nbr]);
					// Check if indegree has become zero, if it has enque it
					if (indegree[nbr] == 0) {
						q.push(nbr);
					}
				}
			}
		}

		//cout << "times : \n";
		for (int i = 0; i < times.size() ; i++) {
			res = max(res, times[i]);
		}


		return count == n ? res : -1;
	}

	int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
		// 	Write your code here

		// Constructing adjacency list and indegree vector
		vector<vector<int>> adjList(n);
		vector<int> indegree(n, 0);
		for (const pair<int, int>& pr : dependency) {
			adjList[pr.first].push_back(pr.second);
			indegree[pr.second]++;
		}

		int minTime = 0;

		return helper(adjList, indegree, duration, n);
	}
};