class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int res = nums.size();

        //cyclic sort
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < nums.size() && nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
            }
            else {
                i++;
            }
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] != i) {
                res = i;
                cout << "Here for i: " << i << " & nums[i] :" << nums[i] << endl;
                break;
            }
        }

        return res;
    }
};