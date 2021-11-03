/*
	$ : AC
*/

class Solution
{
public:
	//Function to find the maximum number of meetings that can
	//be performed in a meeting room.
	int maxMeetings(int start[], int end[], int n) {
		// Your code here

		// Creating a vector with start & time combined
		vector<pair<int, int>> times;
		for (int i = 0; i < n ; i++) {
			times.push_back({start[i], end[i]});
		}

		// Sort according to end time
		sort(times.begin(), times.end(), [ = ](pair<int, int> x, pair<int, int> y) {
			return x.second < y.second ;
		});

		int count = 1 ;

		pair<int, int> prev = times[0];

		for (int i = 1; i < times.size() ; i++) {
			if (times[i].first > prev.second) {
				count++;
				prev = times[i];
			}
		}

		return count;
	}
};