class Solution {
public:

    char helper(vector<char>& letters, char& target) {

        int start = 0 ;
        int end = letters.size() - 1;


        while (start <= end) {

            int mid = start + (end - start) / 2 ;

            if (target < letters[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }

        }

        return letters[start % (letters.size())];
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        return helper(letters, target);
    }
};