/*
    $ : AC
*/

class Solution {
public:

    vector<vector<int>> helper(vector<int>& candidates, int target, int idx) {

        // Base Case.

        if (target == 0)
            return {{}};

        if (target < 0 || idx == candidates.size())
            return {};

        vector<vector<int>> res;

        // Recursive
        // Include
        vector<vector<int>> takeElt = helper(candidates, target - candidates[idx], idx);
        // Append current elt to all the vectors in takeElt
        for (vector<int>& vec : takeElt) {
            vec.push_back(candidates[idx]);
        }

        // Exclude
        vector<vector<int>> excludeElt = helper(candidates, target, idx + 1);

        // Combine takeElt and excludeElt

        for (const vector<int>& vec : takeElt)
            res.push_back(vec);

        for (const vector<int>& vec : excludeElt)
            res.push_back(vec);

        return res;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates, target, 0);
    }
};

/*
    Order of the base cases in this case doesn't matter.
    Before including we can check if it can be done. Doesn't affect overall TC though
    $ : AC
*/

class Solution {
public:

    vector<vector<int>> helper(vector<int>& candidates, int target, int idx) {

        // Base Case.

        if (target < 0 || idx == candidates.size())
            return {};

        if (target == 0)
            return {{}};

        vector<vector<int>> res;

        // Recursive

        // Include
        vector<vector<int>> takeElt;
        // Include only if target-candidates[idx] > 0
        if (target >= candidates[idx]) {
            takeElt = helper(candidates, target - candidates[idx], idx);
        }

        // Append current elt to all the vectors in takeElt
        for (vector<int>& vec : takeElt) {
            vec.push_back(candidates[idx]);
        }

        // Exclude
        vector<vector<int>> excludeElt = helper(candidates, target, idx + 1);

        // Combine takeElt and excludeElt

        for (const vector<int>& vec : takeElt)
            res.push_back(vec);

        for (const vector<int>& vec : excludeElt)
            res.push_back(vec);

        return res;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates, target, 0);
    }
};