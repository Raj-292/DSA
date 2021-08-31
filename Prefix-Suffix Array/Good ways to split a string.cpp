class Solution {
public:


    int numSplits(string s) {


        //precompute the number of distinct letters @ each idx and store.
        vector<bool> distinct(s.size(), false);

        for (int i = 1 ; i < s.size() - 1 ; i++) {
            unordered_map<char, int> mpLeft;
            unordered_map<char, int> mpRight;

            for (int j = 0 ; j < i ; j++) {
                mpLeft[s[j]]++;
            }

            for (int j = i ; j < s.size() - 1 ; j++) {
                mpRight[s[j]]++;
            }

            if (mpLeft.size() == mpRight.size()) {
                distinct[i] = true;
            }

            //for first letter
            unordered_map<char, int> mp1;
            for (int i = 0 ; i < s.size() ; i++) {
                mp1[i]++;
            }
            if (mp1.size() == 1) {
                distinct[0] = true;
            }

            //for last letter
            unordered_map<char, int> mp2;
            for (int i = s.size() - 1 ; i >= 0 ; i--) {
                mp2[i]++;
            }
            if (mp2.size() == 1) {
                distinct[s.size() - 1] = true;
            }

        }


        //bruteforce
        //int splitIdx;

        int cnt = 0;

        for (int i = 1 ; i < s.size() - 1 ; i++ ) {
            if (distinct[i])
                cnt++;
        }

        return ++cnt;

    }
};

// Working Soln :

class Solution {
public:
    int numSplits(string s) {

        //create a prefix array , where pre[i] will contain no of distinct chars
        vector<int> pre(s.size(), 0);
        unordered_map<char, int> mp1;

        for (int i = 0 ; i < s.size() ; i++) {
            mp1[s[i]]++;
            pre[i] = mp1.size();
        }

        //create suffix array

        vector<int> suff(s.size(), 0);
        unordered_map<char, int> mp2;

        for (int i = s.size() - 1 ; i >= 0 ; i--) {
            mp2[s[i]]++;
            suff[i] = mp2.size();
        }

        // for split_idx (1...s.size()-1) check if pre[i]==suff[i]
        int cnt = 0;
        for (int i = 1 ; i < s.size() ; i++) {
            if (pre[i - 1] == suff[i])
                cnt++;
        }

        return cnt;
    }
};