/*
	Old Attempt
	$ : WIP
*/

class Solution {
public:

	bool helper(string& s, vector<string>& wordDict, int idx, int currWordIdx, int& takenSize) {

		cout << "Call parameters : \n";
		cout << "idx : " << idx << "  currWordIdx:  "  << currWordIdx << "  taken Size : " << takenSize << endl;

		// Base Case.

		if (idx == s.size() && takenSize == s.size())
			return true;

		if (currWordIdx > wordDict.size() - 1 || idx > s.size() - 1)
			return false;



		// Place the current word if possible
		bool takeWord = false;
		int ptr1 = idx;
		int k = wordDict[currWordIdx].size();
		if ( (k + idx - 1) < s.size()) {
			if (s.substr(idx, k) == wordDict[currWordIdx]) {
				takenSize += k;
				cout << "true for :" << s.substr(idx, k) << endl;
				takeWord = helper(s, wordDict, idx + k - 1, currWordIdx + 1, takenSize);
			}
		}

		bool notTakeWord = false;


		notTakeWord = helper(s, wordDict, idx, currWordIdx + 1, takenSize);

		return takeWord || notTakeWord;

	}

	bool wordBreak(string s, vector<string>& wordDict) {
		int takenSize = 0;
		return helper(s, wordDict, 0, 0, takenSize);
	}
};


/*
	Using Dynamic Programming
	$ : AC (YT)
*/

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		int n = s.length();
		vector<int> dp(n + 1, 0);

		dp[n] = 1; // true for empty string

		unordered_set<string> dictSet;
		for (const string& word : wordDict)
			dictSet.insert(word);

		// Filling the dp vector
		for (int i = n - 1 ; i >= 0 ; i--) {
			string word;
			for (int j = i ; j < n ; j++) {
				word.push_back(s[j]);
				if (dictSet.find(word) != dictSet.end())
					if (dp[j + 1]) {
						dp[i] = 1;
						break;
					}
			}
		}
		return dp[0];
	}
};