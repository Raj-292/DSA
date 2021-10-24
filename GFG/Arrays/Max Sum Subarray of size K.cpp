/*
    $ : AC
*/

class Solution {
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N) {
        // code here

        // Constructing the prefix sum array
        vector<int> prefixSum (N);
        int cumSum = 0;
        for (int i = 0 ; i < N ; i++) {
            prefixSum[i] = Arr[i] + cumSum;
            cumSum = prefixSum[i];
        }

        int res = 0 ;

        for (int i = 0 ; i <= N - K ; i++) {
            if (i - 1 == -1) {
                res = max(res, prefixSum[i + K - 1]);
            } else {
                res = max(res, prefixSum[i + K - 1] - prefixSum[i - 1]);
            }

        }

        return res;
    }
};