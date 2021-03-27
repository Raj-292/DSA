// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

	string digitToLetter(int x) {
		if (x == 2) {
			return "abc";
		} else if (x == 3) {
			return "def";
		} else if (x == 4) {
			return "ghi";
		} else if (x == 5) {
			return "jkl";
		} else if (x == 6) {
			return "mno";
		} else if (x == 7) {
			return "pqrs";
		} else if (x == 8) {
			return "tuv";
		} else if (x == 9) {
			return "wxyz";
		}

		return "";
	}


	vector<string> f(int a[], int N, int pos) {
		vector<string> res;

		//base case

		if (pos == N) {
			return {""};
		}

		string letters = digitToLetter(a[pos]);
		//all the possibilties for start letter

		for (int x = 0; x < letters.size(); x++) {

			char startLetter = letters[x];

			//append startLetter to all the subsequent buttons
			vector<string> nextButton = f(a, N, pos + 1);

			for (int y = 0; y < nextButton.size(); y++) {
				nextButton[y].insert(nextButton[y].begin(), startLetter);
			}

			for (int j = 0; j < nextButton.size(); j++) {
				res.push_back(nextButton[j]);
			}
		}

		return res;

	}

	vector<string> possibleWords(int a[], int N) {
		//Your code here
		return f(a, N, 0);
	}
};


// { Driver Code Starts.

int main() {

	int T;

	cin >> T; //testcases

	while (T--) { //while testcases exist
		int N;

		cin >> N; //input size of array

		int a[N]; //declare the array

		for (int i = 0; i < N; i++) {
			cin >> a[i]; //input the elements of array that are keys to be pressed
		}

		Solution obj;

		vector <string> res = obj.possibleWords(a, N);
		for (string i : res) cout << i << " ";
		cout << endl;
	}

	return 0;
}  // } Driver Code Ends