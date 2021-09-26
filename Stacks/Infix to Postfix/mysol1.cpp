// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

class Solution
{
public:

    bool isOperand(const char& x) {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
            return true;
        }

        return false;
    }



    string infixToPostfix(string s) {
        // Your code here

        stack<string> st1;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (isOperand) {
                char temp = st1.top();
                st1.pop();
                st1.push(s[i]);
                st1.push(temp);
            } else if (s[i] == '(' || s[i] == ')') {
                continue;
            } else {
                st1.push(s[i]);

            }
        }

        string res;

        while (!st1.empty()) {
            res += st1.top();
            st1.pop();
        }


        return res;


    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
    Improved but still wrong
*/

// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:

    bool isOperand(const char& x) {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
            return true;
        }

        return false;
    }



    string infixToPostfix(string s) {
        // Your code here

        stack<char> st1;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (isOperand(s[i])) {
                char temp = st1.top();
                st1.pop();
                st1.push(s[i]);
                st1.push(temp);
            } else if (s[i] == '(' || s[i] == ')') {
                continue;
            } else {
                st1.push(s[i]);

            }
        }

        string res;

        while (!st1.empty()) {
            res += st1.top();
            st1.pop();
        }


        return res;


    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
// } Driver Code Ends