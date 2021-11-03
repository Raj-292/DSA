/*
    $ : AC
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.

    vector<int> helper(vector<int>& arr, int& n) {

        vector<int> res(n, -1);

        stack<int> st;
        st.push(arr[n - 1]);

        for (int i = n - 2 ; i >= 0 ; i--) {
            while ( !st.empty() && arr[i] > st.top()) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }

            st.push(arr[i]);
        }

        return res;

    }

    vector<int> nextLargerElement(vector<int> arr, int n) {
        // Your code here
        return helper(arr, n);
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector <int> res = obj.nextLargerElement(arr, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends