/*
    $ : AC
*/

class Solution {
public:

    vector<int> helper(vector<int>& nums1, vector<int>& nums2) {

        // Computing the NGE of nums2.
        int n = nums2.size();
        vector<int> nge (n, -1);
        vector<int> res (nums1.size(), -1);
        stack<int> st;
        nge[n - 1] = -1;
        st.push(nums2[n - 1]);

        for (int i = n - 2 ; i >= 0 ; i--) {
            while (!st.empty() && nums2[i] > st.top()) {
                st.pop();
            }

            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

        for (const int& x : nge) {
            cout << x << " ";
        }

        // Traversing through the first array and retreiving the correspoding nge.
        for (int i = 0 ; i < nums1.size() ; i++) {
            vector<int>::iterator itr = find(nums2.begin(), nums2.end(), nums1[i]);
            if (itr != nums2.end()) {
                res[i] = nge[itr - nums2.begin()];
            }
        }

        return res;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2);
    }
};

/*
    Optimized
*/

class Solution {
public:

    vector<int> helper(vector<int>& nums1, vector<int>& nums2) {

        // Common Map.
        unordered_map<int, int> mp;


        // Computing the NGE of nums2.
        int n = nums2.size();
        // nge vector not needed
        //vector<int> nge (n,-1);
        vector<int> res (nums1.size(), -1);
        stack<int> st;
        //nge[n-1] = -1;
        mp[nums2[n - 1]] = -1;
        st.push(nums2[n - 1]);

        for (int i = n - 2 ; i >= 0 ; i--) {
            while (!st.empty() && nums2[i] > st.top()) {
                st.pop();
            }

            if (st.empty()) {
                //nge[i] = -1;
                mp[nums2[i]] = -1;
            } else {
                //nge[i] = st.top();
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // Traversing through the first array and retreiving the correspoding nge.
        for (int i = 0 ; i < nums1.size() ; i++) {
            res[i] = mp[nums1[i]];
        }

        return res;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1, nums2);
    }
};