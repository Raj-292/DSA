/*
	For Kruskal's Algorithm,
	We need to sort the input array which contains:
		- v1 v2 w
			- edge from vertex v1 to v2 og weight w

	For ex :
				- n vertices (n=6)
				- e edges (e=11)

	vector<vector<int>> graph = {

		{0,1,1},
		{0,2,5},
		{2,4,10},
		{0,3,4},
		{1,3,3},
		{1,2,6},
		{3,4,7},
		{2,4,8},
		{4,5,2},
		{2,5,9},
		{3,5,6}
	}

*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 6 ;
	int e = 11;

	vector<vector<int>> graph = {

		{0, 1, 1},
		{0, 2, 5},
		{2, 4, 10},
		{0, 3, 4},
		{1, 3, 3},
		{1, 2, 6},
		{3, 4, 7},
		{2, 4, 8},
		{4, 5, 2},
		{2, 5, 9},
		{3, 5, 6}
	};

	sort(graph.begin(), graph.end(), [ = ](vector<int> v1, vector<int> v2) {
		return v1[2] > v2[2];
	});

	for (vector<int>& x : graph) {
		cout << x[0] << "  " <<  x[1] << "  " << x[2] << endl;
	}

}

/*
	Output :

		2  4  10
		2  5  9
		2  4  8
		3  4  7
		1  2  6
		3  5  6
		0  2  5
		0  3  4
		1  3  3
		4  5  2
		0  1  1


*/