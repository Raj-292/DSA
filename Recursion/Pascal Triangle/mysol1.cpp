// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll int

// } Driver Code Ends
// #define ll int
class Solution {
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here

        //base case
        if (n < 1) {
            return {};
        }

        if (n == 1) {
            return {1};
        }

        if (n == 2) {
            return {1, 1};
        }

        vector<ll> res;

        res.push_back(1);

        vector<ll> prev = nthRowOfPascalTriangle(n - 1);

        for (int i = 1; i < n - 1; i++) {
            res.push_back(prev[i] + prev[i - 1]);
        }

        res.push_back(1);

        return res;
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends

Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
74

Its Correct output is:
1 73 2628 62196 1088430 15020334 170230452 629348605 442125958 82020786 324933029 497343702 569609113 749704286 784446923 352157878 26572299 912624773 394832610 37673337 401718012 585288313 747045099 786926083 222762663 796614822 547596588 175445907 788232565 326567767 345632724 543942166 588924092 34723867 452616317 390058181 356172524 356172524 390058181 452616317 34723867 588924092 543942166 345632724 326567767 788232565 175445907 547596588 796614822 222762663 786926083 747045099 585288313 40.................

And Your Code's output is:
1 73 2628 62196 1088430 15020334 170230452 1629348612 13442126049 97082021465 621324937376 35...

//Maybe replace int with ll
//Replacing int with ll didn't work, the value differs numerically