// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
// public:
void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
    // code here

    //max possible difference is m-n

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
        //cout<<" executed for diff: "<< diff << endl;
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
// };
// { Driver Code Starts.

int main() {

    vector<vector<int> > matrix = {{3, 6, 3, 8, 2}, {4, 1, 9, 5, 9}, {5, 7, 2, 4, 8}, {8, 3, 1, 7, 6}};

    //before sort

    int n = 4; int m = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
            if (j == m - 1) {
                cout << endl;
            }
        }
    }

    diagonalSort(matrix, n, m);

    cout << "after sort:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
            if (j == m - 1) {
                cout << endl;
            }
        }
    }


    return 0;
}

// } Driver Code Ends