/*
	$ : WA
	I/P : "dvdf"
	O/P : 2
	Exp : 3
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		// If string is empty, return 0
		if (s.length() == 0)
			return 0;

		// Vector to store the length of longest substring ending at index i
		vector<int> vec(s.length());

		vec[0] = 1;
		unordered_map<char, int> freq;
		freq[s[0]] = 1;

		for (int i = 1 ; i < s.length() ; i++) {

			// Extend if possible
			if (freq[s[i]] == 0) {
				freq[s[i]]++;
				vec[i] = vec[i - 1] + 1;
			} else {
				freq.clear();
				freq[s[i]]++;
				vec[i] = 1;
			}

		}

		int res = 0;

		for (const int& x : vec)
			res = max(res, x);

		return res;
	}
};

/*
	Implemented using set, [To Do : Can be optimized further]
	$ : AC
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int ptr1 = 0;
		int ptr2 = 0;

		int n = s.length();

		// Unordered set to maintain unique characters
		unordered_set<char> charSet;

		// Initialize the maxLength to 0
		int maxLength = 0;

		while (ptr2 < n) {

			// Insert into the set if the char doesn't exist already
			if (charSet.find(s[ptr2]) == charSet.end()) {
				charSet.insert(s[ptr2]);
				maxLength = max(maxLength, ptr2 - ptr1 + 1);
				ptr2++;
			} else {
				// Char already exists in the set
				// Remove the element at ptr1 and increment ptr1
				charSet.erase(s[ptr1]);
				ptr1++;
			}

		}

		return maxLength;
	}
};