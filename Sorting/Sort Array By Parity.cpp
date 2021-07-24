class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [](int x, int y) {
            // if (x == 1 || y == 1){
            //     return x == 1 ? false : true;
            // }
            return (x % 2 == 0) && (y % 2 != 0) ? true : false ;
        });

        return nums;
    }
};