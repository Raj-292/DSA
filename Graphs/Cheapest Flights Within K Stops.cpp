/*
	$ : WA since INT_MAX case not handled
	I/P : 5 | [[4,1,1],[1,2,3],[0,3,2],[0,4,10],[3,1,1],[1,4,3]] | 2 | 1 | 1
	O/P : 2147483647
	Exp : -1
*/

class Solution {
public:

	int getMin(int& n, vector<pair<int, int>>& price, vector<bool>& visited) {
		int minVertex = -1;
		for (int i = 0 ; i < n ; i++) {
			if (!visited[i]) {
				if (minVertex == -1) {
					minVertex = i;
				} else if (price[i].first < price[minVertex].first)
					minVertex = i;
			}
		}

		return minVertex;
	}

	int helper(int& n, vector<vector<pair<int, int>>>& adjList, int& source, int& dst, int& k) {

		vector<bool> visited(n, false);
		vector<pair<int, int>> price(n, {INT_MAX, 0});

		// Setting the price of source to be 0
		price[source].first = 0;
		price[source].second = -1;

		// Visiting the nodes & their neighbours
		for (int i = 0 ; i < n - 1 ; i++) {
			int minVertex = getMin(n, price, visited);
			// Marking the minVertex visited

			visited[minVertex] = true;

			// Visting the neighbours of minVertex
			for (const pair<int, int>& x : adjList[minVertex]) {
				if (!visited[x.first] && price[minVertex].first != INT_MAX && price[minVertex].second + 1 <= k) {
					if (price[minVertex].first + x.second < price[x.first].first) {
						price[x.first].first = price[minVertex].first + x.second;
						price[x.first].second = price[minVertex].second + 1;
					}
				}
			}
		}

		return price[dst].first;
	}


	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

		vector<vector<pair<int, int>>> adjList (n);
		// In adjList, adjList[x] -> source, adjList[x].first -> dest, adjList[x].second -> weight/price

		// Constructing the adjList
		for (const vector<int>& vec : flights) {
			adjList[vec[0]].push_back({vec[1], vec[2]});
		}

		return helper(n, adjList, src, dst, k);

	}
};

/*
	$ : WA
	I/P : 4 | [[0,1,1],[0,2,5],[1,2,1],[2,3,1]] | 0 | 3 | 1
	O/P : -1
	Exp : 6

	// Since, from node 0 to node 2, stops become 1 but they should be 0 when reached directly by 0
*/

class Solution {
public:

	int getMin(int& n, vector<pair<int, int>>& price, vector<bool>& visited) {
		int minVertex = -1;
		for (int i = 0 ; i < n ; i++) {
			if (!visited[i]) {
				if (minVertex == -1) {
					minVertex = i;
				} else if (price[i].first < price[minVertex].first)
					minVertex = i;
			}
		}

		return minVertex;
	}

	int helper(int& n, vector<vector<pair<int, int>>>& adjList, int& source, int& dst, int& k) {

		vector<bool> visited(n, false);
		vector<pair<int, int>> price(n, {INT_MAX, 0});

		// Setting the price of source to be 0
		price[source].first = 0;
		price[source].second = -1;

		// Visiting the nodes & their neighbours
		for (int i = 0 ; i < n - 1 ; i++) {
			int minVertex = getMin(n, price, visited);
			// Marking the minVertex visited

			visited[minVertex] = true;

			// Visting the neighbours of minVertex
			for (const pair<int, int>& x : adjList[minVertex]) {
				if (!visited[x.first] && price[minVertex].first != INT_MAX && price[minVertex].second + 1 <= k) {
					if (price[minVertex].first + x.second < price[x.first].first) {
						price[x.first].first = price[minVertex].first + x.second;
						price[x.first].second = price[minVertex].second + 1;
					}
				}
			}
		}

		return price[dst].first == INT_MAX ? -1 : price[dst].first;
	}


	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

		vector<vector<pair<int, int>>> adjList (n);
		// In adjList, adjList[x] -> source, adjList[x].first -> dest, adjList[x].second -> weight/price

		// Constructing the adjList
		for (const vector<int>& vec : flights) {
			adjList[vec[0]].push_back({vec[1], vec[2]});
		}

		return helper(n, adjList, src, dst, k);

	}
};