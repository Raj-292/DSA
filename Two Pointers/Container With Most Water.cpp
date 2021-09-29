class Solution {
public:
    int maxArea(vector<int>& height) {

        int areaMax = INT_MIN;

        int p1 = 0;
        int p2 = height.size() - 1;

        while (p1 < p2) {
            areaMax = max(areaMax, (p2 - p1) * min(height[p1], height[p2]));
            if (height[p1] > height[p2])
                p2--;
            else
                p1++;
        }

        return areaMax;
    }
};