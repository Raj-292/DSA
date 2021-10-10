/*
	Sigsegv
*/

void helper(vector<vector<int>>& adjList, vector<bool>& visited, vector<vector<int>>& notAllowed, int startNode, int color, int& res) {

	bool isColorAllowed = true;
	visited[startNode] = true;

	for (const int& clr : notAllowed[startNode]) {
		if (clr == color ) {
			isColorAllowed = false;
			break;
		}
	}

	if (isColorAllowed) {
		// Go through the neighbours
		for (const int& nbr : adjList[startNode]) {
			if (!visited[nbr]) {
				// Set this color as "Not allowed" for neighbours
				notAllowed[nbr].push_back(color);
				helper(adjList, visited, notAllowed, nbr, color + 1, res);
			}

		}
	} else {
		res++;
		helper(adjList, visited, notAllowed, startNode, color + 1, res);
	}

}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V) {
	// your code here

	vector<vector<int>> adjList(21);

	// for(auto x* : graph) {
	//     adjList[x[0]].push_back(x[1]);
	//     adjList[x[1]].push_back(x[0]);
	// }

	for (int i = 0 ; i < 101 ; i++) {
		for (int j = 0 ; j < 101 ; j++) {
			if (graph[i][j] == 1) {
				adjList[i].push_back(j);
			}
		}
	}

	vector<bool> visited (21, false);
	vector<vector<int>> notAllowed(21);

	int res = 0;

	for (int i = 0  ; i < V ; i ++) {
		if (!visited[i])
			helper(adjList, visited, notAllowed, i, 0, res);
	}

	return res;

}

/*
	Seems to be working on Online complier but gives different ans on gfg
*/

#include<bits/stdc++.h>
using namespace std;


void helper(vector<vector<int>>& adjList, vector<bool>& visited, vector<vector<int>>& notAllowed, int startNode, int color, int& res) {

	bool isColorAllowed = true;
	visited[startNode] = true;

	for (const int& clr : notAllowed[startNode]) {
		if (clr == color ) {
			isColorAllowed = false;
			break;
		}
	}

	if (isColorAllowed) {
		// Go through the neighbours
		for (const int& nbr : adjList[startNode]) {
			if (!visited[nbr]) {
				res++;
				// Set this color as "Not allowed" for neighbours
				notAllowed[nbr].push_back(color);
				helper(adjList, visited, notAllowed, nbr, color + 1, res);
			}

		}
	} else {
		res++;
		helper(adjList, visited, notAllowed, startNode, color + 1, res);
	}

}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
int main() {
	// your code here

	vector<vector<int>> graph = {{1, 0, 1, 1}, {0, 0, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 0}};
	int m = 3;
	int V = 4;
	vector<vector<int>> adjList(21);

	// for(auto x* : graph) {
	//     adjList[x[0]].push_back(x[1]);
	//     adjList[x[1]].push_back(x[0]);
	// }

	for (int i = 0 ; i < graph.size() ; i++) {
		for (int j = 0 ; j < graph[i].size() ; j++) {
			if (graph[i][j] == 1) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	vector<bool> visited (21, false);
	vector<vector<int>> notAllowed(21);

	int res = 0;

	for (int i = 0  ; i < V ; i ++) {
		if (!visited[i])
			helper(adjList, visited, notAllowed, i, 0, res);
	}

	cout << "Res is :" <<  res;

}

/*
	Due to return type mismatch, 3 was being returned as 1
		 from line 21, startNode : 0
		Initial res : 0
		After inc. res : 1
		------------------------------------------------------------
		 from line 21, startNode : 1
		Initial res : 1
		After inc. res : 2
		------------------------------------------------------------
		 from line 21, startNode : 2
		Initial res : 2
		After inc. res : 3
		------------------------------------------------------------
		Ans res : 3
		1

	$ : WA
	I/P : 13 | 4 | 15 | 11 12 2 8 1 2 11 13 5 8 3 13 9 11 2 12 6 8 12 13 6 10 5 10 4 6 10 13 8 9
	O/P : 0
	Exp : 1
*/

void helper(vector<vector<int>>& adjList, vector<bool>& visited, vector<vector<int>>& notAllowed, int startNode, int color, int& res) {

	bool isColorAllowed = true;
	visited[startNode] = true;

	for (const int& clr : notAllowed[startNode]) {
		if (clr == color ) {
			isColorAllowed = false;
			break;
		}
	}

	if (isColorAllowed) {
		// Go through the neighbours
		for (const int& nbr : adjList[startNode]) {
			if (!visited[nbr]) {
				res++;
				// Set this color as "Not allowed" for neighbours
				notAllowed[nbr].push_back(color);
				helper(adjList, visited, notAllowed, nbr, color + 1, res);
			}

		}
	} else {
		res++;
		helper(adjList, visited, notAllowed, startNode, color + 1, res);
	}

}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V) {
	// your code here

	vector<vector<int>> adjList(21);

	// for(auto x* : graph) {
	//     adjList[x[0]].push_back(x[1]);
	//     adjList[x[1]].push_back(x[0]);
	// }

	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; j < V ; j++) {
			if (graph[i][j]) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	vector<bool> visited (21, false);
	vector<vector<int>> notAllowed(21);

	int res = 0;

	for (int i = 0  ; i < V ; i ++) {
		if (!visited[i])
			helper(adjList, visited, notAllowed, i, 0, res);
	}

	return res <= m ? true : false;

}

/*
	WIP
*/

void helper(vector<vector<int>>& adjList, vector<bool>& visited, vector<vector<int>>& notAllowed, int startNode, int color, int& res) {

	bool isColorAllowed = true;
	visited[startNode] = true;

	for (const int& clr : notAllowed[startNode]) {
		if (clr == color ) {
			isColorAllowed = false;
			break;
		}
	}

	if (isColorAllowed) {
		// Go through the neighbours
		//res++;
		for (const int& nbr : adjList[startNode]) {
			if (!visited[nbr]) {
				//res++;
				// Set this color as "Not allowed" for neighbours
				notAllowed[nbr].push_back(color);
				helper(adjList, visited, notAllowed, nbr, color, res);
			}

		}
	} else {
		res++;
		for (int i = 0 ; i < 100 ; i++) {
			vector<int>::iterator itr;
			itr = std::find (notAllowed[startNode].begin(), notAllowed[startNode].end(), i);
			if (itr ==  notAllowed[startNode].end())
				helper(adjList, visited, notAllowed, startNode, i, res);
		}

	}

}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V) {
	// your code here

	vector<vector<int>> adjList(21);

	// for(auto x* : graph) {
	//     adjList[x[0]].push_back(x[1]);
	//     adjList[x[1]].push_back(x[0]);
	// }

	for (int i = 0 ; i < V ; i++) {
		for (int j = 0 ; j < V ; j++) {
			if (graph[i][j]) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	vector<bool> visited (21, false);
	vector<vector<int>> notAllowed(21);

	int res = 0;

	for (int i = 0  ; i < V ; i ++) {
		if (!visited[i])
			helper(adjList, visited, notAllowed, i, 0, res);
	}

	cout << "Res value : " << res << endl;

	return res <= m ? true : false;
}

/*
	$ : WA
	I/P : 11 | 4 | 26 | 4 10 1 3 6 10 5 10 8 9 4 6 4 7 3 9 8 11 10 11 6 8 6 11 7 10 5 9 2 3 7 11 5 11 2 6 7 8 1 8 1 4 1 11 2 9 1 7 3 8 4 11
	O/P : 0
	Exp : 1
*/