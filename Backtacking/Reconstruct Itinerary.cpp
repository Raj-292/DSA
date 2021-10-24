/*
	JFK is not being considered again since it was already visited
	$ : WA
*/

class Solution {
public:

	void helper(unordered_map<string, vector<string>>& adjList, unordered_map<string, bool>& visited, string currAirport, vector<string>& res) {

		// Mark current Airport as visted
		visited[currAirport] = true;

		// Add to res
		res.push_back(currAirport);

		// Visit the neighbours in lexicographical order
		vector<string> nbrs = adjList[currAirport];

		// Sort nbrs
		sort(nbrs.begin(), nbrs.end());

		// Go through neighbours
		for (const string& nbr : nbrs) {
			if (!visited[nbr])
				helper(adjList, visited, nbr, res);
		}


		return;
	}


	vector<string> findItinerary(vector<vector<string>>& tickets) {

		unordered_map<string, vector<string>> adjList;
		unordered_map<string, bool> visited;

		// Initialize visited to false
		for (const vector<string>& ticket : tickets) {
			visited[ticket[0]] = false;
			visited[ticket[1]] = false;
		}


		for (const vector<string>& ticket : tickets) {
			adjList[ticket[0]].push_back(ticket[1]);
		}


		// Res vector
		vector<string> res;

		helper(adjList, visited, "JFK", res);

		return res;
	}
};

/*
	Can add recStack (detect cycle in directed graph)
	$ : Still WA
	I/P : [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
	O/P : ["JFK","ATL","SFO","SFO","ATL"]
	Exp : ["JFK","ATL","JFK","SFO","ATL","SFO"]
*/

class Solution {
public:

	void helper(unordered_map<string, vector<string>>& adjList, unordered_map<string, bool>& visited, unordered_map<string, bool>& recStack, string currAirport, vector<string>& res) {

		// Mark current Airport as visted
		visited[currAirport] = true;
		recStack[currAirport] = true;

		// Add to res
		res.push_back(currAirport);

		// Visit the neighbours in lexicographical order
		vector<string> nbrs = adjList[currAirport];

		// Sort nbrs
		sort(nbrs.begin(), nbrs.end());

		// Go through neighbours
		for (const string& nbr : nbrs) {
			if (!recStack[nbr])
				helper(adjList, visited, recStack, nbr, res);
		}

		recStack[currAirport] = false;

		return;
	}


	vector<string> findItinerary(vector<vector<string>>& tickets) {

		unordered_map<string, vector<string>> adjList;
		unordered_map<string, bool> visited;
		unordered_map<string, bool> recStack;

		// Initialize visited to false
		for (const vector<string>& ticket : tickets) {
			visited[ticket[0]] = false;
			visited[ticket[1]] = false;
		}

		// Initialize recStack to false
		for (const vector<string>& ticket : tickets) {
			recStack[ticket[0]] = false;
			recStack[ticket[1]] = false;
		}

		for (const vector<string>& ticket : tickets) {
			adjList[ticket[0]].push_back(ticket[1]);
		}


		// Res vector
		vector<string> res;

		helper(adjList, visited, recStack, "JFK", res);

		return res;
	}
};

/*
	Stack overflow
*/

class Solution {
public:

	void helper(unordered_map<string, vector<string>>& adjList, unordered_map<string, bool>& visited, unordered_map<string, bool>& recStack, string currAirport, vector<string>& res) {

		// Mark current Airport as visted
		visited[currAirport] = true;
		recStack[currAirport] = true;

		// Add to res
		res.push_back(currAirport);

		// Visit the neighbours in lexicographical order
		vector<string> nbrs = adjList[currAirport];

		// Sort nbrs
		sort(nbrs.begin(), nbrs.end());


		// Go through neighbours
		for (const string& nbr : nbrs) {

			if (!visited[nbr])
				helper(adjList, visited, recStack, nbr, res);

			if (visited[nbr] && recStack[nbr])
				helper(adjList, visited, recStack, nbr, res);

		}

		recStack[currAirport] = false;

		return;
	}


	vector<string> findItinerary(vector<vector<string>>& tickets) {

		unordered_map<string, vector<string>> adjList;
		unordered_map<string, bool> visited;
		unordered_map<string, bool> recStack;

		// Initialize visited to false
		for (const vector<string>& ticket : tickets) {
			visited[ticket[0]] = false;
			visited[ticket[1]] = false;
		}

		// Initialize recStack to false
		for (const vector<string>& ticket : tickets) {
			recStack[ticket[0]] = false;
			recStack[ticket[1]] = false;
		}

		for (const vector<string>& ticket : tickets) {
			adjList[ticket[0]].push_back(ticket[1]);
		}


		// Res vector
		vector<string> res;

		helper(adjList, visited, recStack, "JFK", res);

		return res;
	}
};

/*
	Somewhat close
*/

class Solution {
public:

	void helper(unordered_map<string, vector<string>>& adjList, unordered_map<string, bool>& visited, unordered_map<string, bool>& recStack, string currAirport, vector<string>& res) {

		// Mark current Airport as visted
		visited[currAirport] = true;
		recStack[currAirport] = true;

		// Add to res
		res.push_back(currAirport);

		// Visit the neighbours in lexicographical order
		vector<string> nbrs = adjList[currAirport];

		// Sort nbrs
		sort(nbrs.begin(), nbrs.end());


		// Go through neighbours
		for (const string& nbr : nbrs) {

			if (!visited[nbr]) {
				helper(adjList, visited, recStack, nbr, res);
			}

		}

		res.insert(res.begin(), currAirport);


		recStack[currAirport] = false;

		return;
	}


	vector<string> findItinerary(vector<vector<string>>& tickets) {

		unordered_map<string, vector<string>> adjList;
		unordered_map<string, bool> visited;
		unordered_map<string, bool> recStack;

		// Initialize visited to false
		for (const vector<string>& ticket : tickets) {
			visited[ticket[0]] = false;
			visited[ticket[1]] = false;
		}

		// Initialize recStack to false
		for (const vector<string>& ticket : tickets) {
			recStack[ticket[0]] = false;
			recStack[ticket[1]] = false;
		}

		for (const vector<string>& ticket : tickets) {
			adjList[ticket[0]].push_back(ticket[1]);
		}


		// Res vector
		vector<string> res;

		helper(adjList, visited, recStack, "JFK", res);

		return res;
	}
};

/*
	Kept a visited array such that, it will keep a track of from where it was visited.
	It will visit that airport again if and only if that airport is not visited by the current airport previously
	Example test cases passed
	$ : WA
	I/P : [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
	O/P : ["JFK","KUL","NRT","JFK"]
	Exp : ["JFK","NRT","JFK","KUL"]
*/

class Solution {
public:

	void helper(unordered_map<string, vector<string>>& adjList, unordered_map<string, vector<string>>& visited, string currAirport, string sourceAirport, vector<string>& res) {

		// Mark current Airport as visted
		visited[currAirport].push_back(sourceAirport);

		// Add to res
		res.push_back(currAirport);

		// Visit the neighbours in lexicographical order
		vector<string> nbrs = adjList[currAirport];

		// Sort nbrs
		sort(nbrs.begin(), nbrs.end());

		// Go through neighbours
		for (const string& nbr : nbrs) {

			// Check if the visited of nbr contains this parent already
			bool isVisitedByParent = false;

			for (const string& prt : visited[nbr]) {
				if (prt == currAirport) {
					isVisitedByParent = true;
					break;
				}
			}

			if (!isVisitedByParent) {
				helper(adjList, visited, nbr, currAirport, res);
			}
		}

		return;
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {

		unordered_map<string, vector<string>> adjList;
		unordered_map<string, vector<string>> visited;

		for (const vector<string>& ticket : tickets) {
			adjList[ticket[0]].push_back(ticket[1]);
		}

		// Res vector
		vector<string> res;

		helper(adjList, visited, "JFK", "-1", res);

		return res;
	}
};

