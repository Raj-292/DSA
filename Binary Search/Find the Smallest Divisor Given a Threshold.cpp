/*
	$ : AC
*/

class Solution {

private:
	bool isPossible(vector<int>& nums, int& k, int& threshold) {
		int sum = 0 ;

		for (int i = 0 ; i < nums.size() ; i++)
			sum += (nums[i] + k - 1) / k;

		return sum <= threshold ? true : false;
	}

public:
	int smallestDivisor(vector<int>& nums, int threshold) {

		// No predicate framework
		// Maximum logicial divisor would be the largest number in the array
		int hi = nums[0];
		for (const int& num : nums)
			hi = max(hi, num);

		int lo = 1;

		int mid;
		int res;

		while (lo < hi) {

			mid = lo + (hi - lo) / 2;

			if (isPossible(nums, mid, threshold)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		return lo;
	}
};

/*
	Using Casting
	$ : AC
*/

class Solution {

private:
	bool isPossible(vector<int>& nums, int& k, int& threshold) {
		int sum = 0 ;

		for (int i = 0 ; i < nums.size() ; i++)
			sum += ceil((float)nums[i] / k);

		return sum <= threshold ? true : false;
	}

public:
	int smallestDivisor(vector<int>& nums, int threshold) {

		// No predicate framework
		// Maximum logicial divisor would be the largest number in the array
		int hi = nums[0];
		for (const int& num : nums)
			hi = max(hi, num);

		int lo = 1;

		int mid;
		int res;

		while (lo < hi) {

			mid = lo + (hi - lo) / 2;

			if (isPossible(nums, mid, threshold)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		return lo;
	}
};

/*
	DMX - Using predicate framework
*/

class Solution {
public:
	int S(vector<int>& nums, int d) {
		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			sum += ceil((float)nums[i] / d);
		}

		return sum;
	}

	int smallestDivisor(vector<int>& nums, int threshold) {
		// FFFTTTTT
		// first T
		// p(x): S(x) <= threshold
		int maxE = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
			maxE = max(maxE, nums[i]);

		int lo = 1, hi = maxE, mid;

		while (lo < hi) {
			mid = lo + (hi - lo) / 2;

			if (S(nums, mid) <= threshold)
				hi = mid;
			else
				lo = mid + 1;
		}

		return lo;
	}
};