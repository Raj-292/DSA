/*
	Added Check for INT_MAX @ end
	$ : Line 27: Char 90: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
		SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:36:90
		for input :  [[2,1,1],[2,3,1],[3,4,1]]|4|1
*/

class Solution {
public:

	int getMin(vector<int>& totalTime, vector<bool>& visited) {
		int minValIdx = -1;

		for (int i = 1 ; i < totalTime.size() ; i++) {
			if (!visited[i] && (minValIdx == -1 || totalTime[i] < totalTime[minValIdx]))
				minValIdx = i;
		}

		return minValIdx;
	}

	int helper(vector<vector<pair<int, int>>>& adjList, vector<int>& totalTime , vector<bool>& visited, int n , int source) {

		totalTime[source] = 0;

		// Considering all the nodes
		for (int i = 1 ; i < n ; i++) {
			int minValIdx = getMin(totalTime, visited);
			visited[minValIdx] = true;

			// Relax operation on all the neighbours
			for (const pair<int, int>& nbr : adjList[minValIdx]) {
				if (!visited[nbr.first]) {
					totalTime[nbr.first] = min(totalTime[nbr.first], totalTime[minValIdx] + nbr.second);
				}
			}
		}

		// Returning the maximum time in totalTime
		int maxDelay = totalTime[1];
		for (int j = 2 ; j < n + 1 ; j++) {
			maxDelay = max(maxDelay, totalTime[j]);
		}

		return maxDelay;
	}


	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		// Constructing an adjacency list
		// in pair -> first : node , second : time
		vector<vector<pair<int, int>>> adjList(n + 1);

		for (const vector<int>& x : times)
			adjList[x[0]].push_back({x[1], x[2]});

		// Total time array
		vector<int> totalTime(n + 1, INT_MAX);

		// Fixed time array
		vector<bool> visited(n + 1, false);

		int res = helper(adjList, totalTime, visited, n, k);

		return res == INT_MAX ? -1 : res ;
	}
};

/*
	Added condition : totalTime[minValIdx] != INT_MAX along with the visited cond in if check
	$ : AC
*/

class Solution {
public:

	int getMin(vector<int>& totalTime, vector<bool>& visited) {
		int minValIdx = -1;

		for (int i = 1 ; i < totalTime.size() ; i++) {
			if (!visited[i] && (minValIdx == -1 || totalTime[i] < totalTime[minValIdx]))
				minValIdx = i;
		}

		return minValIdx;
	}

	int helper(vector<vector<pair<int, int>>>& adjList, vector<int>& totalTime , vector<bool>& visited, int n , int source) {

		totalTime[source] = 0;

		// Considering all the nodes
		for (int i = 1 ; i < n ; i++) {
			int minValIdx = getMin(totalTime, visited);
			visited[minValIdx] = true;

			// Relax operation on all the neighbours
			for (const pair<int, int>& nbr : adjList[minValIdx]) {
				if (!visited[nbr.first] && totalTime[minValIdx] != INT_MAX) {
					totalTime[nbr.first] = min(totalTime[nbr.first], totalTime[minValIdx] + nbr.second);
				}
			}
		}

		// Returning the maximum time in totalTime
		int maxDelay = totalTime[1];
		for (int j = 2 ; j < n + 1 ; j++) {
			maxDelay = max(maxDelay, totalTime[j]);
		}

		return maxDelay;
	}


	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		// Constructing an adjacency list
		// in pair -> first : node , second : time
		vector<vector<pair<int, int>>> adjList(n + 1);

		for (const vector<int>& x : times)
			adjList[x[0]].push_back({x[1], x[2]});

		// Total time array
		vector<int> totalTime(n + 1, INT_MAX);

		// Fixed time array
		vector<bool> visited(n + 1, false);

		int res = helper(adjList, totalTime, visited, n, k);

		return res == INT_MAX ? -1 : res ;
	}
};