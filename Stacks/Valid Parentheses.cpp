/*
	Do not miss out the case where a closing bracket is encountered when the stack is empty.
	Ex : "([)]"
	     Here, the stack will be empty when the flow is at ']'. So, in that case add it to the stack

	$ : Failing for TC : "(]". O/P = true, Exp : false
	  : When flow comes at ']', it is not added to the stack since the stack is not empty. Hence, the stack keeps on getting emptied.
	  : Will have to add one more check for that
*/

class Solution {
public:

	bool helper(string& s) {

		stack<char> st;

		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			} else if (s[i] == ')') {

				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '(') {
						st.pop();
					}
					if (!st.empty())st.pop();
				}

			} else if (s[i] == '}') {

				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '{') {
						st.pop();
					}
					if (!st.empty())st.pop();
				}

			} else {

				if (st.empty()) {
					st.push(s[i]);
				} else {

					while (!st.empty() && st.top() != '[') {
						st.pop();
					}
					if (!st.empty())st.pop();
				}

			}
		}

		if (st.empty())
			return true;

		return false;

	}


	bool isValid(string s) {
		return helper(s);
	}
};

/*
	After every if (!st.empty())st.pop(); , added else return false; => This will handle the case when the opening bracket which was expected
	was not found and the stack got empty;
	$ : 89 / 91 test cases passed.
	  : Input: "({[)" , Output: true , Expected: false
	  => Since at last closing ')' is encountered, it keeps on emptying the stack till '(' is encountered
	  => One hacky way to tackle this could be to increment count by 1 when encountering opening bracket and decrement by one when closing
	  => Keep three such variables
*/


class Solution {
public:

	bool helper(string& s) {

		stack<char> st;

		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			} else if (s[i] == ')') {

				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '(') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			} else if (s[i] == '}') {

				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '{') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			} else {

				if (st.empty()) {
					st.push(s[i]);
				} else {

					while (!st.empty() && st.top() != '[') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			}
		}

		if (st.empty())
			return true;

		return false;

	}


	bool isValid(string s) {
		return helper(s);
	}
};

/*
	Added 3 variables to keep count of the 3 types
	$ : AC
	Only these 3 variables without the rest of the logic won't suffice. For ex : "([)]"
*/

class Solution {
public:

	bool helper(string& s) {

		stack<char> st;

		int count1 = 0;
		int count2 = 0;
		int count3 = 0;

		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
				if (s[i] == '(') count1++;
				if (s[i] == '{') count2++;
				if (s[i] == '[') count3++;
			} else if (s[i] == ')') {
				count1--;
				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '(') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			} else if (s[i] == '}') {
				count2--;
				if (st.empty()) {
					st.push(s[i]);
				} else {
					while (!st.empty() && st.top() != '{') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			} else {
				count3--;
				if (st.empty()) {
					st.push(s[i]);
				} else {

					while (!st.empty() && st.top() != '[') {
						st.pop();
					}
					if (!st.empty())st.pop();
					else return false;
				}

			}
		}

		if (st.empty() && count1 == 0 && count2 == 0 && count3 == 0)
			return true;

		return false;

	}


	bool isValid(string s) {
		return helper(s);
	}
};

/*
	Extra variables not required
*/

class Solution {
public:

	bool isPair(char& x, char& y) {
		if (x == '{' && y == '}')
			return true;
		if (x == '(' && y == ')')
			return true;
		if (x == '[' && y == ']')
			return true;
		return false;
	}

	bool helper(string& s) {

		stack<char> st;

		for (int i = 0; i < s.size() ; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				st.push(s[i]);
			else {
				if (st.empty())
					return false;
				else if (!isPair(st.top(), s[i]))
					return false;
				else {
					st.pop();
				}
			}
		}

		return (st.empty());

	}

	bool isValid(string s) {
		return helper(s);
	}
};