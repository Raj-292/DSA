/*
    $ : AC
*/

class Solution {
public:

    string getChars(int x) {

        if (x == 2) {
            return "abc";
        } else if (x == 3) {
            return "def";
        } else if (x == 4) {
            return "ghi";
        } else if (x == 5) {
            return "jkl";
        } else if (x == 6) {
            return "mno";
        } else if (x == 7) {
            return "pqrs";
        } else if (x == 8) {
            return "tuv";
        } else if (x == 9) {
            return "wxyz";
        }

        return "";
    }

    vector<string> helper(string& digits, int idx) {

        // Base Case

        if (digits.size() == 0)
            return {};

        if (idx == digits.size())
            return {""};


        vector<string> res;

        // Recursive
        string possibleChars = getChars(digits[idx] - '0');

        // Next letter
        vector<string> v = helper(digits, idx + 1);

        // Each of the letters in possibleChars is a potential inclusion
        for (const char& ch : possibleChars) {

            vector<string> vCopy = v;

            // Append char ch to all strings in vCopy
            for (string& s : vCopy) {
                s = ch + s;
            }

            // Push all strings in vCopy to res
            for (const string& s : vCopy)
                res.push_back(s);
        }

        return res;
    }

    vector<string> letterCombinations(string digits) {
        return helper(digits, 0);
    }
};