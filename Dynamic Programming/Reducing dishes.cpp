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
