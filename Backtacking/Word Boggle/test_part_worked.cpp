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

		map<string, bool> mp;

		for (int i = 0; i < dictionary.size(); i++) {
			string word = dictionary[i];
			for (int x = 0; x < board.size(); x++) {
				for (int y = 0; y < board.size(); y++) {
					if (board[x][y] == word[0]) {
						if (doesExist(board, word, 0, x, y)) {
							res.push_back(word);
							mp[word] = true;
							break;
						}
					}
					if (mp[word]) {
						break;
					}
				}

				if (mp[word]) {
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



//Wrong Answer.

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
4
dff b ec efe
2 5
f d b c e
f d c c f

Its Correct output is:
b dff ec

And Your Code's output is:
dff


Now there was a bug (int y = 0; y < board.size(); y++  instead of (int y = 0; y < board[0].size(); y++)

                     Code :

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
                     using namespace std;


// } Driver Code Ends

class Solution {
public:

	bool isValid(vector<vector<char> >& board, string & word, int ptr, int row, int col) {
		int m = board.size();
		int n = board[0].size();

		if (row < 0 || row > (m - 1) || col < 0 || col > (n - 1)) {
			return false;
		} else if (board[row][col] != word[ptr]) {
			return false;
		}

		return true;
	}

	bool doesExist(vector<vector<char> >& board, string & word, int ptr, int row, int col) {

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

		map<string, bool> mp;

		for (int i = 0; i < dictionary.size(); i++) {
			string word = dictionary[i];
			for (int x = 0; x < board.size(); x++) {
				for (int y = 0; y < board[0].size(); y++) {
					if (board[x][y] == word[0]) {
						if (doesExist(board, word, 0, x, y)) {
							res.push_back(word);
							mp[word] = true;
							break;
						}
					}
					if (mp[word]) {
						break;
					}
				}

				if (mp[word]) {
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

Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
10
vdkfi xyzrf izog homkjqhvr f ri gafo ivkdhqlgwcic b b
42 49
k u f w p g j o s r o t h k b e o l h t g l e h g w l i y s y x c y t a e x n x o t p l p n d y c
r n n d s h j a w n i t c f w d b t o t s m m d p i e b c t t k b k b w d e i p f n s u u y v r l
k l f r k u d g j u b q z e o e d j d g e w i y x m v e m e v v e d u i a y v w s b v j c d l q h
m n p n x d r m v u v a j h l l j f d j k p r z y j r g h p v d i g p o p p o x c d a j x n v a g
c v g b q r l m t x e w y f j i n a i s b s b.................

Its Correct output is:
b b f gafo homkjqhvr ivkdhqlgwcic izog ri vdkfi xyzrf

And Your Code's output is:
b f gafo homkjqhvr ivkdhqlgwcic izog ri vdkfi xyzrf


So maps will have to be removed, instead a visited array should be used.