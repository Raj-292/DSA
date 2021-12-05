/*
	$ : WA
	I/P : [-2,3,-4]
	O/P : 3
	Exp : 24

	Reason : When comparing a negative existing sum to nums[i], we do not know if there is a negative number present ahead which can make the res positive
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		// Result array
		vector<int> res(nums.size());

		res[0] = nums[0];

		for (int i = 1 ; i < res.size() ; i++)
			res[i] = max(res[i - 1] * nums[i], nums[i]);

		int ans = res[0];

		for (const int& x : res)
			ans = max(ans, x);

		return ans;
	}
};

/*
	$ : WA
	Reason :  When a single element is present, it is giving INT_MIN as ans
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		// MinProd array
		vector<int> minProd(nums.size());
		// MaxProd array
		vector<int> maxProd(nums.size());

		minProd[0] = nums[0];
		maxProd[0] = nums[0];
		int ans = INT_MIN;

		for (int i = 1 ; i < nums.size() ; i++) {
			minProd[i] = min({minProd[i - 1]*nums[i], maxProd[i - 1]*nums[i], nums[i]});
			maxProd[i] = max({minProd[i - 1]*nums[i], maxProd[i - 1]*nums[i], nums[i]});
			ans = max(ans, maxProd[i]);
		}

		return ans;
	}
};

/*
	Ans can be initialized to the first element itself.
	Alternative : Offset array by 1 and initialize ans with INT_MIN
	$ : AC
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		// MinProd array
		vector<int> minProd(nums.size());
		// MaxProd array
		vector<int> maxProd(nums.size());

		minProd[0] = nums[0];
		maxProd[0] = nums[0];
		int ans = nums[0];

		for (int i = 1 ; i < nums.size() ; i++) {
			minProd[i] = min({minProd[i - 1]*nums[i], maxProd[i - 1]*nums[i], nums[i]});
			maxProd[i] = max({minProd[i - 1]*nums[i], maxProd[i - 1]*nums[i], nums[i]});
			ans = max(ans, maxProd[i]);
		}

		return ans;
	}
};