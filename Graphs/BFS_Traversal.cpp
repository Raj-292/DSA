#include <bits/stdc++.h>

using namespace std;

#define ll long long


void bfs(vector<vector<int>>& adjMat, vector<bool>& visited) {

	queue<int> q;

	q.push(0);

	visited[0] = true;

	while (!q.empty()) {
		int frontElt = q.front();
		q.pop();
		cout << frontElt << " ";

		//visiting the neighbours of frontElt
		for (int i = 0 ; i < adjMat[0].size() ; i++) {
			if (adjMat[frontElt][i] && !visited[i])	{
				q.push(i);
				visited[i] = true;
			}
		}

	}


}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;

	cin >> v >> e ;

	//creating adjacency matrix
	vector<vector<int>> adjMat (v, vector<int>(v, 0));

	//visited vector
	vector<bool> visited(v, false);

	for (int i = 0 ; i < e ; i++) {
		int x, y;
		cin >> x >> y;
		adjMat[x][y] = 1;
	}

	// for (int i = 0 ; i < adjMat.size() ; i++) {
	// 	for (int j = 0 ; j < adjMat[0].size() ; j++) {
	// 		cout << adjMat[i][j] << " ";
	// 		if (j == adjMat[0].size() - 1)
	// 			cout << '\n';
	// 	}
	// }

	bfs(adjMat, visited);


}