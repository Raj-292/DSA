#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;
    vector<pair<int, int>> times(n);

    int maxTime = 0;

    unordered_map<int, int> starts;
    unordered_map<int, int> ends;

    for (int i = 0 ; i < n ; i++) {
        int x, y;
        cin >> x >> y;
        times[i] = {x, x + y};
        starts[x]++;
        ends[x + y]++;
        maxTime = max(maxTime, x + y);
    }

    int count = 0;
    unordered_map<int, int> res;

    for (int i = 0 ; i < maxTime ; i++) {
        count += (starts[i]);
        count -= (ends[i]);
        res[count]++;
    }

    for (int i = 1; i <= n ; i++) {
        cout << res[i] << " ";
    }

    return 0;
}
