// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        // code here

        //max possible difference is max(m,n)

        //upper triangular matrix
        for (int diff = 1; diff <= max(m, n) ; diff++) {
            vector<int> elts;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((j - i) == diff) {
                        elts.push_back(matrix[i][j]);
                    }
                }
            }

            sort(elts.begin(), elts.end());

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((j - i) == diff) {
                        matrix[i][j] = elts.back();
                        elts.pop_back();
                    }
                }
            }
        }

        //lower triangular matrix
        for (int diff = -1; diff >= min(-m, -n) ; diff--) {
            vector<int> elts;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((j - i) == diff) {
                        elts.push_back(matrix[i][j]);
                    }
                }
            }

            sort(elts.begin(), elts.end(), greater<int>());

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((j - i) == diff) {
                        matrix[i][j] = elts.back();
                        elts.pop_back();
                    }
                }
            }
        }
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int inputline2[n * m];
        for (int i = 0; i < n * m; ++i)
            cin >> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j];
            }
        }

        Solution ob;
        ob.diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends

/*
Runtime Error:
Runtime ErrorTime Limit Exceeded

Your program took more time than expected.Time Limit Exceeded
Expected Time Limit 2.20sec
Hint : Please optimize your code and submit again.
*/