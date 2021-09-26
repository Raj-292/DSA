/*
	TC getting passed.
	$ : SIGSEGV on N = 6, price[] = [10 4 5 90 120 80]
	  : caused at :  res.push_back(i-(st.top().second)); (since stack may be empty)
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
public:
	//Function to calculate the span of stockâ€™s price for all n days.

	vector<int> helper(int price[], int n) {

		// Pair -> value, index
		stack<pair<int, int>> st;
		vector<int> res;

		st.push({price[0], 0});
		res.push_back(1);

		for (int i = 1 ; i < n ; i++) {
			if (price[i] >= st.top().first) {
				while (!st.empty() && st.top().first <= price[i]) {
					st.pop();
				}
				res.push_back(i - (st.top().second));
				st.push({price[i], i});
			} else {
				st.push({price[i], i});
				res.push_back(1);
			}
		}

		return res;
	}


	vector <int> calculateSpan(int price[], int n) {
		// Your code here
		return helper(price, n);
	}
};



// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends

/*
	Added the check where the stack might become empty when an element is encountered such that no greater element is ever encountered before
	$ : AC
	# : Can we just keep the index and do away with the value ?
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
public:
	//Function to calculate the span of stockâ€™s price for all n days.

	vector<int> helper(int price[], int n) {

		// Pair -> value, index
		stack<pair<int, int>> st;
		vector<int> res;

		st.push({price[0], 0});
		res.push_back(1);

		for (int i = 1 ; i < n ; i++) {
			if (price[i] >= st.top().first) {
				while (!st.empty() && st.top().first <= price[i]) {
					st.pop();
				}
				if (!st.empty()) {
					res.push_back(i - (st.top().second));
					st.push({price[i], i});
				} else {
					st.push({price[i], i});
					res.push_back(i + 1);
				}

			} else {
				st.push({price[i], i});
				res.push_back(1);
			}
		}

		return res;
	}


	vector <int> calculateSpan(int price[], int n) {
		// Your code here
		return helper(price, n);
	}
};



// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends