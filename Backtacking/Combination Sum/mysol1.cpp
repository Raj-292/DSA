// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:


    vector<vector<int> > f(vector<int>& arr, int remSum, int pos) {

        vector<vector<int> > res;

        //base case
        if (pos == arr.size() || remSum < 0) {
            return {}
        }

        if (remSum == 0) {
            return {{}};
        }

        //include the digit @ pos
        vector<vector<int> > inc = f(arr, remSum - arr[pos], pos + 1);
        //append the digit @ pos to all vectors in inc
        for (int i = 0; i < inc.size(); i++) {
            inc[i].push_back(arr[pos]);
        }

        //omit the digit @ pos
        vector<vector<int> > notInc = f(arr, remSum, pos + 1);

        //combining both possibilities
        res = inc;
        for (int i = 0; i < notInc.size(); i++) {
            res.push_back(notInc[i]);
        }
        return res;
    }

    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        return f(A, B, 0);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0) {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++) {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}     // } Driver Code Ends