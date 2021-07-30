class Solution {
public:

    int helper(vector<int> satisfaction, int idx) {

        //base case
        if (satisfaction.size() == 0 || idx == satisfaction.size())
            return 0;

        //take or not

        //take
        int takeElt = (idx + 1) * satisfaction[idx] + helper(satisfaction, idx + 1);

        //not take
        //if we do not take elt, we will have to shift the vector elts towards left
        vector<int>::iterator itr = satisfaction.begin();
        satisfaction.erase(itr + idx);
        int notTakeElt = helper(satisfaction, idx);

        return max(takeElt, notTakeElt);

    }

    int maxSatisfaction(vector<int>& satisfaction) {

        // sort the satisfaction vector in ascending order
        sort(satisfaction.begin(), satisfaction.end());
        return helper(satisfaction, 0);


    }
};

// Although this is a valid solution, it will cause TLE for larger test cases
// Approach in mind : instead of shifting the elements itself, keep passing a variable which keeps a track of ignored elements which keeps on accumulating.


class Solution {
public:

    int helper(vector<int>& satisfaction, vector<vector<int>>& dp, int idx, int shift) {

        //base case
        if (satisfaction.size() == 0 || idx == satisfaction.size())
            return 0;

        //take or not

        if (dp[idx][shift] == -1) {
            //take
            int takeElt = (idx + 1 - shift) * satisfaction[idx] + helper(satisfaction, dp, idx + 1, shift);

            //not take
            //if we do not take elt, we will have to shift the vector elts towards left
            //vector<int>::iterator itr = satisfaction.begin();
            //satisfaction.erase(itr + idx);
            int notTakeElt = helper(satisfaction, dp, idx + 1 , shift + 1);

            int res = max(takeElt, notTakeElt);
            dp[idx][shift] = res;
            return res;
        } else {
            return dp[idx][shift];
        }

    }

    int maxSatisfaction(vector<int>& satisfaction) {

        // sort the satisfaction vector in ascending order
        sort(satisfaction.begin(), satisfaction.end());

        //create DP matrix {idx,shift}

        vector<vector<int>>dp (satisfaction.size(), vector<int>(satisfaction.size(), -1));


        return helper(satisfaction, dp, 0, 0);


    }
};

// Accepted : 46ms, 20.9 MB