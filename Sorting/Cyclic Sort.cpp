#include <bits/stdc++.h>

using namespace std;

#define ll int

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // array will contain 1 to 5
    int n = 5;

    vector<int> v = {3, 5, 2, 1, 4};

    // Cyclic Sort

    int i = 0;
    while (i < v.size() - 1) {
        if (v[i] != i + 1) {
            swap(v[i], v[v[i] - 1]);
        } else {
            i++;
        }
    }

    for (const int& x : v) {
        cout << x << " ";
    }

}




