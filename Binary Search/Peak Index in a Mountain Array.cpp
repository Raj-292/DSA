/*
	Using Predicate framework
*/

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		// FFFFTTTT
		// p(x): arr[x] < arr[x-1]
		// Last F
		int n = arr.size(), lo, hi, mid;

		lo = 0, hi = n - 1;
		while (lo < hi) {
			mid = lo + (hi - lo + 1) / 2;

			if (arr[mid] < arr[mid - 1])
				hi = mid - 1;
			else
				lo = mid;
		}

		// Sanity check - Not required since peak is guaranteed to exist
		return lo;

	}
};