/*
	$ : TLE (	34 / 38 test cases passed.)
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// Bruteforce

		//int temp;

		while (k--) {
			int p1 = nums.size() - 1;
			int temp = nums[p1];
			while (p1 > 0) {
				nums[p1] = nums[p1 - 1];
				p1--;
			}
			nums[0] = temp;
		}

		return;
	}
};

/*
	Optimized, but not O(N) extra space
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// Optimized but not in-place

		vector<int> numsCopy = nums;

		int n = nums.size();

		for (int i = 0 ; i < nums.size() ; i++) {
			int newIdx =  (i + k) % n;
			numsCopy[newIdx] = nums[i];
		}

		// Overwrite nums with numsCopy
		nums = numsCopy;

		return;
	}
};

/*
	Works for TC 1 :
	I/P : [1,2,3,4,5,6,7] ,3
	O/P : [5,6,7,1,2,3,4]
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		int temp;

		temp = nums[0];

		int p1 = 0;
		int n = nums.size();

		while (p1 < nums.size()) {

			if ((n - k + p1) % n == 0) {
				nums[p1] = temp;
				break;
			}

			nums[p1] = nums[(n - k + p1) % n];
			p1 = (n - k + p1) % n;

			for (auto num : nums) {
				cout << num << " ";
			}
			cout << endl;
		}

	}
};

/*
	In place and using reverse
	$ : Runtime Error (4 / 38 test cases passed.)
	I/P :[-1], 2
	O/P : -
	Exp :
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// In place and using reverse()

		int n = nums.size();


		// First reverse last k elements
		reverse(nums.begin() + (n - k) % n, nums.end());

		// Reverse whole array
		reverse(nums.begin(), nums.end());

		// Reverse last (n-k) elements
		reverse(nums.begin() + (k % n), nums.end());

		return;
	}
};

/*
	Added check for single element
	$ : Seg fault
	I/P :  [1,7] , 3
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// In place and using reverse()

		int n = nums.size();

		if (n == 1)
			return;

		// First reverse last k elements
		reverse(nums.begin() + (n - k) % n, nums.end());

		// Reverse whole array
		reverse(nums.begin(), nums.end());

		// Reverse last (n-k) elements
		reverse(nums.begin() + (k % n), nums.end());

		return;
	}
};

/*
	Added check in case k>n
	$ : WA
	I/P : [1,2] , 0
	O/P : [2,1]
	Exp : [1,2]
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// In place and using reverse()

		int n = nums.size();

		if (n == 1)
			return;

		if (k > n) {
			k %= n;
		}

		// First reverse last k elements
		reverse(nums.begin() + (n - k) % n, nums.end());

		// Reverse whole array
		reverse(nums.begin(), nums.end());

		// Reverse last (n-k) elements
		reverse(nums.begin() + (k % n), nums.end());

		return;
	}
};

/*
	Removed unnecessary mods
	$ : AC
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		// In place and using reverse()

		int n = nums.size();

		if (n == 1)
			return;

		if (k > n) {
			k %= n;
		}

		// First reverse last k elements
		reverse(nums.begin() + (n - k), nums.end());

		// Reverse whole array
		reverse(nums.begin(), nums.end());

		// Reverse last (n-k) elements
		reverse(nums.begin() + k, nums.end());

		return;
	}
};