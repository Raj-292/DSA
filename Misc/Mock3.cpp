#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int getMinMaxDiff(vector<int>& arr) {

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0 ; i < arr.size() ; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    if (minVal == INT_MAX && maxVal == INT_MIN) {
        return INT_MAX;
    } else {
        return maxVal - minVal;
    }

}

vector<vector<int>> getSubSeq(vector<int>& arr, int idx) {

    // Base Case
    if (idx == arr.size()) {
        return {{}};
    }

    // Take curr index element
    vector<vector<int>> takeElt = getSubSeq(arr, idx + 1);
    // Append current index element to each of the vectors
    for (vector<int>& vct : takeElt) {
        vct.push_back(arr[idx]);
    }


    // Ignore it
    vector<vector<int>> IgnoreElt = getSubSeq(arr, idx + 1);

    // Combine takeElt and Ignore Elt

    for (const vector<int>& vct : IgnoreElt) {
        takeElt.push_back(vct);
    }

    return takeElt;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t; cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> entries(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> entries[i];
        }

        // Assuming lowest possible value of p i.e 2
        int p = 2;

        // Check diversity for every segment of size p
        vector<vector<int>> allSubSeq = getSubSeq(vector<int> &entries, 0);

        while (true) {
            for (const vector<int>& v : allSubSeq) {
                if (getMinMaxDiff(v)) {

                }
            }

        }




    }

    return 0;
}

/* ---------------------------------------------------------------------------------------------- */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int getMinMaxDiff(vector<int>& arr) {

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0 ; i < arr.size() ; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    if (minVal == INT_MAX && maxVal == INT_MIN) {
        return INT_MAX;
    } else {
        return maxVal - minVal;
    }

}

vector<vector<int>> getSubSeq(vector<int>& arr, int idx) {

    // Base Case
    if (idx == arr.size()) {
        return {{}};
    }

    // Take curr index element
    vector<vector<int>> takeElt = getSubSeq(arr, idx + 1);
    // Append current index element to each of the vectors
    for (vector<int>& vct : takeElt) {
        vct.push_back(arr[idx]);
    }


    // Ignore it
    vector<vector<int>> IgnoreElt = getSubSeq(arr, idx + 1);

    // Combine takeElt and Ignore Elt

    for (const vector<int>& vct : IgnoreElt) {
        takeElt.push_back(vct);
    }

    return takeElt;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t; cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> entries(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> entries[i];
        }

        vector<vector<int>> allSubSeq = getSubSeq(entries, 0);

        bool isDiverse = false;

        while (!isDiverse) {

            // Assuming lowest possible value of p i.e 2
            int p = 2;

            bool isPValid = true;

            // Check diversity for every segment of size p
            for (int i = 0 ; i < allSubSeq.size() ; i++) {
                if (allSubSeq[i].size() == p) {
                    int div = getMinMaxDiff(allSubSeq[i]);
                    if (div > d) {
                        isPValid = false;
                        break;
                    }
                }
            }

            if (isPValid) {
                cout << p;
                break;
            }

            p++;

        }


    }

    return 0;
}

