
// Incomplete

class Solution {
public:

    string helper(string s) {


        //base case : no bracket
        int cnt = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '[')
                cnt++;
        }

        if (cnt == 0)
            return s;

        //split strategy
        //pass in only the stuff inside brackets -> evaluate the brackets -> multiply with the factor

        //bracket
        int brackCount = 0;
        int brackStart = -1;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '[') {
                if (brackStart == -1)
                    brackStart = i;
                brackCount++;
            }

        }
        int brackCountCopy = brackCount;
        int brackEnd = -1;
        for (int i = brackStart ; i < s.size() ; i++) {
            if (s[i] == ']') {
                brackCount--;
                if (brackCount == 0)
                    brackEnd = i;
            }
        }

        //Now we have brackStart & brackEnd
        //pass on to helper
        string fromHelper = helper(s.substr(brackStart, brackEnd));


        //normal


    }


    string decodeString(string s) {

    }
};