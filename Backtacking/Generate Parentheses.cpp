/*
	$ : WA
	I/P : 8
	I/P : 7
	I/P : 6
	I/P : 5
	I/P : 4 => Missing (())(())
	I/P : {3 to 1} => Correct
*/

class Solution {
public:

	vector<string> helper(int k) {

		vector<string> res;
		unordered_map<string, int> mp;

		// Base case
		if (k == 1) {
			return {"()"};
		}

		// Recursive

		vector<string> nextCombination = helper(k - 1);
		// Wrap around existing ones
		vector<string> wrap = nextCombination;
		for (string& s : wrap) {
			s = '(' + s + ')';
		}

		// Add next to existing
		vector<string> nextToExisting = nextCombination;
		for (string& s : nextToExisting) {
			s = s + "()";
		}

		// Add before existing
		vector<string> beforeExisting = nextCombination;
		for (string& s : beforeExisting) {
			s = "()" + s;
		}


		// Add wrap and nextToExisiting strings to res;

		for (const string& s : wrap)
			mp[s]++;

		for (const string& s : nextToExisting)
			mp[s]++;

		for (const string& s : beforeExisting)
			mp[s]++;

		for (auto x : mp)
			res.push_back(x.first);

		return res;
	}


	vector<string> generateParenthesis(int n) {
		return helper(n);
	}
};