/*
	$: TLE
	 : for I/P -[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1] , 27
*/

class Solution {
public:

	vector<vector<int>> helper(vector<int>& candidates, int target, int idx) {

		// Base Case.

		if (target == 0)
			return {{}};

		if (target < 0 || idx == candidates.size())
			return {};

		vector<vector<int>> res;

		// Recursive
		// Include
		vector<vector<int>> takeElt = helper(candidates, target - candidates[idx], idx + 1);
		// Append current elt to all the vectors in takeElt
		for (vector<int>& vec : takeElt) {
			vec.push_back(candidates[idx]);
		}

		// Exclude
		vector<vector<int>> excludeElt = helper(candidates, target, idx + 1);

		// Combine takeElt and excludeElt

		for (const vector<int>& vec : takeElt)
			res.push_back(vec);

		for (const vector<int>& vec : excludeElt)
			res.push_back(vec);

		// Remove duplicates
		for (vector<int>& vec : res)
			sort(vec.begin(), vec.end());
		set<vector<int>> st;
		for (const vector<int>& vec : res)
			st.insert(vec);

		// Creating array to hold unique vectors
		vector<vector<int>> uniqueRes;

		set<vector<int>> :: iterator itr;
		for (itr = st.begin(); itr != st.end(); itr++)
			uniqueRes.push_back(*itr);

		return uniqueRes;
	}


	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		return helper(candidates, target, 0);
	}
};

/*
	 $: TLE
	  : Works for smaller TC but still TLE for above I/P
*/

class Solution {
public:

	vector<vector<int>> helper(vector<int>& candidates, int target, int idx) {

		// Base Case.

		if (target == 0)
			return {{}};

		if (target < 0 || idx == candidates.size())
			return {};

		vector<vector<int>> res;

		// Recursive
		// Include
		vector<vector<int>> takeElt = helper(candidates, target - candidates[idx], idx + 1);
		// Append current elt to all the vectors in takeElt
		for (vector<int>& vec : takeElt) {
			vec.push_back(candidates[idx]);
		}

		// Exclude
		vector<vector<int>> excludeElt = helper(candidates, target, idx + 1);

		// Combine takeElt and excludeElt

		set<vector<int>> st;

		for (vector<int>& vec : takeElt) {
			sort(vec.begin(), vec.end());
			if (st.find(vec) == st.end()) {
				res.push_back(vec);
				st.insert(vec);
			}
		}

		for (vector<int>& vec : excludeElt) {
			sort(vec.begin(), vec.end());
			if (st.find(vec) == st.end()) {
				res.push_back(vec);
				st.insert(vec);
			}
		}

		return res;
	}


	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		return helper(candidates, target, 0);
	}
};