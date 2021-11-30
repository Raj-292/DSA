/*
	Using Predicate Framework
	$ : AC
*/

class Solution {
public:

	int firstOccurence(vector<int>& nums, int& k, int low, int hi) {
		// p(x) : x < K => T*F*. First F

		while (low < hi) {

			// Choice of mid
			int mid = low + (hi - low) / 2;

			// Decision
			if (nums[mid] < k)
				low = mid + 1;
			else
				hi = mid;
		}

		// Sanity check
		if (nums[low] == k)
			return low;

		return -1;
	}

	int lastOccurence(vector<int>& nums, int& k, int low, int hi) {
		// p(x) : x <= K => T*F*. Last T

		while (low < hi) {
			// Choice of mid
			int mid = low + (hi - low + 1) / 2;

			// Decision
			if (nums[mid] <= k)
				low = mid;
			else
				hi = mid - 1;
		}


		// Sanity check
		if (nums[low] == k)
			return low;

		return -1;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();

		if (n == 0)
			return { -1, -1};

		return {firstOccurence(nums, target, 0, n - 1), lastOccurence(nums, target, 0, n - 1)};

	}
};

/*
	Using F*T*
	$ : AC (DMX)
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0) return { -1, -1};

		vector<int> res;
		// First position
		// FFFFTTT
		// p(x): x >= target
		// First T
		int lo = 0, hi = nums.size() - 1, mid;

		while (lo < hi) {
			// choice of mid
			mid = lo + (hi - lo) / 2;

			// Decision
			if (nums[mid] >= target)
				hi = mid;
			else
				lo = mid + 1;
		}

		// Sanity check
		if (nums[lo] == target)
			res.push_back(lo);
		else
			return { -1, -1};

		// Last position
		// If I reach here, that element exists
		// res contains the index of the starting
		// FFFFTTT
		// p(x): x > target
		// last F

		// No need of resetting low
		hi = nums.size() - 1;

		while (lo < hi) {
			mid = lo + (hi - lo + 1) / 2;

			if (nums[mid] > target)
				hi = mid - 1;
			else
				lo = mid;
		}

		// Sanity Check
		// No need of sanity check
		res.push_back(lo);


		return res;
	}
};