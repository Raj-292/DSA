/*
	$ : 63 / 80 test cases passed.
	I/P : "mississippi","issip"
	O/P : -1
	Exp : 4
*/

class Solution {
public:
	int strStr(string haystack, string needle) {

		if (needle.size() == 0)
			return 0;

		int p1 = 0;
		int p2 = 0;
		int idx = 0;
		while (p1 < haystack.size() && haystack[p1] != needle[p2]) {
			p1++;
		}

		idx = p1;

		while (p2 < needle.size() && p1 < haystack.size() && haystack[p1] == needle[p2]) {
			p1++;
			p2++;
		}

		if (p2 == needle.size()) {
			return idx;
		}

		return -1;
	}
};

/*
	Bruteforce
	$ : AC
*/

class Solution {
public:
	int strStr(string haystack, string needle) {

		if (needle.size() == 0) {
			return 0;
		}

		for (int i = 0 ; i < haystack.size() ; i++) {
			if (haystack[i] == needle[0]) {
				int k = i;
				int m = 0;
				while (k < haystack.size() && m < needle.size() && haystack[k] == needle[m]) {
					k++;
					m++;
				}

				if (m == needle.size())
					return i;

			}
		}

		return -1;
	}
};