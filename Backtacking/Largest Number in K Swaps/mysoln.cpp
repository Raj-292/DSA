// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:

    int strToInt(string& s) {
        int x = 0; // may take int
        for (int i = 0; i < s.length(); i++)
            x = x * i + s[i] - '0';
        return x;
    }

    string getMax(string str, int rem_swaps, int ptr) {

        //base case
        if (ptr == str.size() - 1) {
            return "" ;
        }

        if (rem_swaps <= 0) {
            return str;
        }

        //swap idx @ ptr
        string with_swap;
        with_swap = str;

        int max_num = -1;
        int max_idx = ptr;

        for (int i = ptr + 1; i < str.size(); i++) {
            char tmp = str[i];
            //cout << tmp << endl;
            if (tmp - '0' > max_num) {
                max_num = tmp - '0' ;
                max_idx = i;
            }
        }
        if (with_swap[ptr] < with_swap[max_idx]) {
            swap(with_swap[ptr], with_swap[max_idx]);
        }


        string c1 = getMax(with_swap, rem_swaps - 1, ptr + 1);
        //append first elt to c1
        //c1 = with_swap[0]+c1;

        //no swap
        string c2 = getMax(str, rem_swaps, ptr + 1);
        //append first elt to c1
        c2 = str[0] + c2;

        return strToInt(c1) >= strToInt(c2) ? c1 : c2;
    }



    string findMaximumNum(string str, int k) {
        // code here.
        return getMax(str, k, 0);
    }
};

// { Driver Code Starts.

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Above soln is working


/*
Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
4
1234567

Its Correct output is:
7654321

And Your Code's output is:
77654321
*/

/*
Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
3
4551711527

Its Correct output is:
7755511124

And Your Code's output is:
7755411125
*/

//https://ide.geeksforgeeks.org/ePLow4cuom