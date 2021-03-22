// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:

	bool isValid(vector<vector<char> >& board, string& word, int ptr, int row, int col) {
		int m = board.size();
		int n = board[0].size();

		if (row < 0 || row > (m - 1) || col < 0 || col > (n - 1)) {
			return false;
		} else if (board[row][col] != word[ptr]) {
			return false;
		}

		return true;
	}

	bool doesExist(vector<vector<char> >& board, string& word, int ptr, int row, int col) {

		//base case
		if (ptr == word.size()) {
			return true;
		}

		if (ptr > word.size()) {
			return false;
		}

		if (!isValid(board, word, ptr, row, col)) {
			return false;
		}

		//mark visited
		board[row][col] = '#';

		// We can move to 8 adjacent characters
		bool up = doesExist(board, word, ptr + 1, row - 1, col);
		bool down = doesExist(board, word, ptr + 1, row + 1, col);
		bool right = doesExist(board, word, ptr + 1, row, col + 1);
		bool left = doesExist(board, word, ptr + 1, row, col - 1);
		bool up_right = doesExist(board, word, ptr + 1, row - 1, col + 1);
		bool up_left = doesExist(board, word, ptr + 1, row - 1, col - 1);
		bool down_right = doesExist(board, word, ptr + 1, row + 1, col + 1);
		bool down_left = doesExist(board, word, ptr + 1, row + 1, col - 1);

		board[row][col] = word[ptr];

		bool res = (up || down || right || left || up_right || up_left || down_right || down_left);

		return res;
	}

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
		// Code here

		vector<string> res;

		//map<string, bool> mp;
		vector<bool> visited(dictionary.size(), false);

		for (int i = 0; i < dictionary.size(); i++) {
			string word = dictionary[i];
			for (int x = 0; x < board.size(); x++) {
				for (int y = 0; y < board[0].size(); y++) {
					if (board[x][y] == word[0]) {
						if (doesExist(board, word, 0, x, y)) {
							res.push_back(word);
							//mp[word] = true;
							visited[i] = true;
							break;
						}
					}
					if (visited[i]) {
						break;
					}
				}

				if (visited[i]) {
					break;
				}
			}
		}
		return res;
	}
};
// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		vector<string> dictionary;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			dictionary.push_back(s);
		}

		int R, C;
		cin >> R >> C;
		vector<vector<char> > board(R);
		for (int i = 0; i < R; i++) {
			board[i].resize(C);
			for (int j = 0; j < C; j++) cin >> board[i][j];
		}
		Solution obj;
		vector<string> output = obj.wordBoggle(board, dictionary);
		if (output.size() == 0)
			cout << "-1";
		else {
			sort(output.begin(), output.end());
			for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
		}
		cout << endl;
	}
}
// } Driver Code Ends

Correct Answer.Correct Answer
Execution Time: 0.14