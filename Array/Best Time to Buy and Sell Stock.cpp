/*
	$ : WA
	I/P : [2,4,1]
	O/P : 0
	Exp : 2
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		int lowestPrice = INT_MAX;
		int lowest_idx = 0;

		int i;
		for (i = 0 ; i < n ; i++) {
			if (prices[i] < lowestPrice) {
				lowestPrice = prices[i];
				lowest_idx = i;
			}
		}

		// Go through right of lowest_idx and find the highest point
		int highestPrice = lowestPrice;
		int highest_idx = lowest_idx;

		for (int j = lowest_idx ; j < n ; j++) {
			if (prices[j] > highestPrice) {
				highestPrice = prices[j];
				highest_idx = j;
			}
		}

		return highestPrice - lowestPrice;
	}
};

/*
	$ : AC
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int minPrice = INT_MAX;
		int res = 0;

		for (const int& x : prices) {
			minPrice = min(minPrice, x);
			res = max(res, x - minPrice);
		}

		return res;
	}
};