
/* This is giving SigSegV fault */

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int equalPartition(int N, int arr[]) {
        // code here

        int totalSum = 0;

        for (int i = 0 ; i < N ; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 2 != 0)
            return 0;

        int newSize = (totalSum / 2);
        vector<vector<int>> dp(N + 1, vector<int>(newSize + 1, -1));

        //setting first row to be false
        for (int i = 0; i < newSize + 1 ; i++) {
            dp[0][i] = 0;
        }

        //setting first column to be true
        for (int i = 0; i < N + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the values
        for (int i = 1 ; i < N + 1 ; i++) {
            for (int j = 1 ; j < newSize + 1 ; j++) {
                if (arr[i - 1] <= newSize) {
                    dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][newSize];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends


/* Sigsev solved but wrong answer
    instead of dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
    it was dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j];
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int equalPartition(int N, int arr[]) {
        // code here

        int totalSum = 0;

        for (int i = 0 ; i < N ; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 2 != 0)
            return 0;

        int newSize = (totalSum / 2);
        vector<vector<int>> dp(N + 1, vector<int>(newSize + 1, -1));

        //setting first row to be false
        for (int i = 0; i < newSize + 1 ; i++) {
            dp[0][i] = 0;
        }

        //setting first column to be true
        for (int i = 0; i < N + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the values
        for (int i = 1 ; i < N + 1 ; i++) {
            for (int j = 1 ; j < newSize + 1 ; j++) {
                if (arr[i - 1] <= newSize) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][newSize];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends

/* Accepted
    instead of if (arr[i - 1] <= j)
    it was if (arr[i - 1] <= newSize)
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int equalPartition(int N, int arr[]) {
        // code here

        int totalSum = 0;

        for (int i = 0 ; i < N ; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 2 != 0)
            return 0;

        int newSize = (totalSum / 2);
        vector<vector<int>> dp(N + 1, vector<int>(newSize + 1, -1));

        //setting first row to be false
        for (int i = 0; i < newSize + 1 ; i++) {
            dp[0][i] = 0;
        }

        //setting first column to be true
        for (int i = 0; i < N + 1 ; i++) {
            dp[i][0] = 1;
        }

        //setting the rest of the values
        for (int i = 1 ; i < N + 1 ; i++) {
            for (int j = 1 ; j < newSize + 1 ; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][newSize];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends