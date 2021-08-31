/*
    $ : AC

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> res;

        //cyclic sort
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

/*
    No need of && @ line 10
    $ : AC
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> res;

        //cyclic sort
        int i = 0;
        while (i < nums.size()) {
            if (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;

    }
};