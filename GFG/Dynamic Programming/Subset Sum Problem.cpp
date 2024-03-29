// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    bool isSubsetSum(int N, int arr[], int sum) {

        vector<vector<bool>> dp(N, vector<bool>(sum + 1, false));

        for (int i = 0; i < N ; i++) {
            dp[i][0] = true;
            if (arr[i] <= sum)
                dp[i][arr[i]] = true; // this condition is necessary
        }

        //  for(int i = 0; i < sum+1 ; i++ ) {
        //     if(arr[N-1] == sum)
        //         dp[N-1][i] = true;
        //  }                           // this condition not necessary



        for (int i = N - 2; i >= 0 ; i--) {
            for (int j = 1 ; j < sum + 1 ; j++) {
                if (j - arr[i] > 0) {
                    dp[i][j] = dp[i + 1][j - arr[i]] || dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        // cout << "DP start :\n";

        // for(int x = 0 ; x < dp.size() ; x++){
        //   for(int y = 0 ; y <dp[0].size();y++){
        //       cout<<dp[x][y] << "       ";
        //       if(y==dp[0].size()-1){
        //           cout<<endl;
        //         }
        //     }

        // }

        // cout << "DP END :\n";

        // bool res = false;

        //for(int i = 0 ; i < N+1 ; i++) {
        //   res = res || dp[i][sum];
        // }

        //cout <<"Res: "<< res;

        return dp[0][sum];

    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Top-Down Approach

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    bool isSubsetSum(int N, int arr[], int sum) {
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));

        //dp[N][i] -> false

        for (int i = 0 ; i < sum + 1 ; i++) {
            dp[N][i] = 0;
        }

        //dp[0][i] = true;

        for (int i = 0; i < N + 1 ; i++) {
            dp[i][0] = 1;
        }

        for (int i = N - 1; i >= 0 ; i--) {
            for (int j = 1 ; j < sum + 1 ; j++) {
                if (arr[i] <= sum) {
                    dp[i][j] = dp[i + 1][j - arr[i]] || dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
    AV Approach
    $ : AC
*/

class Solution {
public:
    bool isSubsetSum(int N, int arr[], int sum) {
        // code here

        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));

        // Initializing the 1st column to true
        for (int i = 0 ; i < N + 1 ; i++) {
            dp[i][0] = true;
        }

        for (int i = 1 ; i < N + 1 ; i++) {
            for (int j = 1 ; j < sum + 1 ; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][sum];
    }
};