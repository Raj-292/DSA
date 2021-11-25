/*
	$ : AC
*/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		// Sort by start time
		sort(intervals.begin(), intervals.end());

		vector<int> prev = intervals[0];
		vector<vector<int>> res;

		for (int i = 1 ; i < intervals.size() ; i++) {
			// Not overlapping
			if (intervals[i][0] > prev[1]) {
				res.push_back(prev);
				prev = intervals[i];
			} else {
				// Overlapping
				prev[1] = max(prev[1], intervals[i][1]);
			}
		}

		// Pushing the last remaining one
		res.push_back(prev);

		return res;
	}
};