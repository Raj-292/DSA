// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

long long  numberOfPaths(int m, int n) {
	// Code Here

	//long long res;

	//invalid
	if (m < 0 || n < 0) {
		return 0;
	}

	//base case
	if (m == 1 && n == 1) {
		return 1;
	}


	//down
	long long d_path = numberOfPaths(m - 1, n);

	//right
	long long r_path = numberOfPaths(m, n - 1);

	return d_path + r_path ;


}
// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> m >> n;
		cout << numberOfPaths(m, n) << endl;
	}
	return 0;
}  // } Driver Code Ends


Correct Answer.Correct Answer
Execution Time: 0.01