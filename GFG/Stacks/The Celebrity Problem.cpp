/*
	$ : TLE
*/

class Solution
{
public:
	//Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int> >& M, int n) {
		// code here
		stack<int> st;

		// Push 0 .. n-1 in stack
		for (int i = 0 ; i < n ; i++)
			st.push(i);

		while (st.size() > 1) {

			// At a time, remove top 2 elements and push one of them back
			int first = st.top(); st.pop();
			int second = st.top(); st.pop();

			if (M[first][second] != 1)
				st.push(first);

			if (M[second][first] != 1)
				st.push(second);

		}

		return st.size() == 1 ? st.top() : -1;
	}
};

/*
	$ : AC
*/

class Solution
{
public:
	//Function to find if there is a celebrity in the party or not.
	int celebrity(vector<vector<int> >& M, int n) {
		// code here
		stack<int> st;

		// Push 0 .. n-1 in stack
		for (int i = 0 ; i < n ; i++)
			st.push(i);

		while (st.size() > 1) {

			// At a time, remove top 2 elements and push one of them back
			int first = st.top(); st.pop();
			int second = st.top(); st.pop();

			if (M[first][second] == 0)
				st.push(first);
			else
				st.push(second);

		}

		int last = st.top();

		for (int i = 0 ; i < n ; i++)
			if (M[last][i] == 1)
				return -1;

		for (int i = 0 ; i < n ; i++)
			if (M[i][last] == 0 && i != last)
				return -1;

		return last;
	}
};