/*
	Given TC passed
	$ : TLE
*/

class Solution
{
public:

	void isCircle(int& N, unordered_map<string, vector<string>>& mp, unordered_map<string, int>& visited, string currString) {

		visited[currString]++;

		// Visit the neighbours
		for (const string& nbr : mp[currString]) {
			if (visited[nbr] < 1) {
				isCircle(N, mp, visited, nbr);
			}
		}

	}

	int isCircle(int N, vector<string> A) {
		// code here

		// Make a directed connection (x -> y) if last letter of x is equal to first letter of y
		unordered_map<string, vector<string>> mp;

		for (const string& s : A) {
			string u = s;
			char last = u[u.length() - 1];
			for (const string& x : A) {
				if (x == s) {
					continue;
				} else {
					if (x[0] == last) {
						mp[u].push_back(x);
					}
				}
			}
		}

		unordered_map<string, int> visited;
		for (const string& s : A) {
			visited[s] = false;
		}

		isCircle(N, mp, visited, A[0]);

		for (int i = 0; i < A.size() ; i++) {
			if (visited[A[i]] != 1)
				return 0;
		}

		return 1;
	}
};

/*
	Created 2 maps for start and end chars
	$ : WA
	I/P : 1 | odbmrmayzr
	O/P : 1
	Exp : 0
*/

class Solution
{
public:

	void isCircle(int& N, unordered_map<string, vector<string>>& mp, unordered_map<string, int>& visited, string currString) {

		visited[currString]++;

		// Visit the neighbours
		for (const string& nbr : mp[currString]) {
			if (visited[nbr] < 1) {
				isCircle(N, mp, visited, nbr);
			}
		}

	}

	int isCircle(int N, vector<string> A) {
		// code here

		// Make a directed connection (x -> y) if last letter of x is equal to first letter of y
		unordered_map<char, vector<string>> endChar;
		unordered_map<char, vector<string>> startChar;
		unordered_map<string, vector<string>> mp;

		for (const string& s : A) {
			endChar[s[s.length() - 1]].push_back(s);
			startChar[s[0]].push_back(s);
		}

		// Connect endChars ---> startChars
		for (auto x : endChar) {

			vector<string>& startCharacters = startChar[x.first];
			// Connect
			for (const string& str1 : x.second) {
				for (const string& str2 : startCharacters) {
					mp[str1].push_back(str2);
				}
			}
		}

		unordered_map<string, int> visited;
		for (const string& s : A) {
			visited[s] = false;
		}

		isCircle(N, mp, visited, A[0]);

		for (int i = 0; i < A.size() ; i++) {
			if (visited[A[i]] != 1)
				return 0;
		}

		return 1;
	}
};

/*
	Added check when there is only 1 string
	$ : WA
	I/P : 2
		  rffacpqrao ogkzvbsjpa
	O/P : 1
	Exp : 0

*/

class Solution
{
public:

	void isCircle(int& N, unordered_map<string, vector<string>>& mp, unordered_map<string, int>& visited, string currString) {

		visited[currString]++;

		// Visit the neighbours
		for (const string& nbr : mp[currString]) {
			if (visited[nbr] < 1) {
				isCircle(N, mp, visited, nbr);
			}
		}

	}

	int isCircle(int N, vector<string> A) {
		// code here

		if (N == 1)
			return A[0][0] == A[0][A[0].length() - 1] ? 1 : 0;

		// Make a directed connection (x -> y) if last letter of x is equal to first letter of y
		unordered_map<char, vector<string>> endChar;
		unordered_map<char, vector<string>> startChar;
		unordered_map<string, vector<string>> mp;

		for (const string& s : A) {
			endChar[s[s.length() - 1]].push_back(s);
			startChar[s[0]].push_back(s);
		}

		// Connect endChars ---> startChars
		for (auto x : endChar) {

			vector<string>& startCharacters = startChar[x.first];
			// Connect
			for (const string& str1 : x.second) {
				for (const string& str2 : startCharacters) {
					mp[str1].push_back(str2);
				}
			}
		}

		unordered_map<string, int> visited;
		for (const string& s : A) {
			visited[s] = false;
		}

		isCircle(N, mp, visited, A[0]);

		for (int i = 0; i < A.size() ; i++) {
			if (visited[A[i]] != 1)
				return 0;
		}

		return 1;
	}
};

/*
	Fixed initializaton of visited vector from visited[s] = false to visited[s] = -1
	$ : TLE
*/

class Solution
{
public:

	void isCircle(int& N, unordered_map<string, vector<string>>& mp, unordered_map<string, int>& visited, string currString) {

		visited[currString]++;

		// Visit the neighbours
		for (const string& nbr : mp[currString]) {
			if (visited[nbr] < 1) {
				isCircle(N, mp, visited, nbr);
			}
		}

	}

	int isCircle(int N, vector<string> A) {
		// code here

		if (N == 1)
			return A[0][0] == A[0][A[0].length() - 1] ? 1 : 0;

		// Make a directed connection (x -> y) if last letter of x is equal to first letter of y
		unordered_map<char, vector<string>> endChar;
		unordered_map<char, vector<string>> startChar;
		unordered_map<string, vector<string>> mp;

		for (const string& s : A) {
			endChar[s[s.length() - 1]].push_back(s);
			startChar[s[0]].push_back(s);
		}

		// Connect endChars ---> startChars
		for (auto x : endChar) {

			vector<string>& startCharacters = startChar[x.first];
			// Connect
			for (const string& str1 : x.second) {
				for (const string& str2 : startCharacters) {
					mp[str1].push_back(str2);
				}
			}
		}

		unordered_map<string, int> visited;
		for (const string& s : A) {
			visited[s] = -1;
		}

		isCircle(N, mp, visited, A[0]);

		for (int i = 0; i < A.size() ; i++) {
			if (visited[A[i]] != 1)
				return 0;
		}

		return 1;
	}
};

/*
	Comment Solution 1
*/

class Solution
{
	int graph[26][26];
	void dfs(int v, vector<bool> &visited)
	{
		visited[v] = true;
		for (int i = 0 ; i < 26 ; i++)
			if (graph[v][i] && !visited[i])
				dfs(i, visited);
	}
public:
	int isCircle(int N, vector<string> A)
	{
		memset(graph, 0, sizeof(graph));
		vector<int> in(26, 0);
		vector<int> out(26, 0);
		for (int i = 0 ; i < N ; i++)
		{
			int a = A[i][0] - 'a';
			int b = A[i].back() - 'a';
			in[a]++;
			out[b]++;
			graph[a][b] = 1;
		}
		for (int i = 0 ; i < 26 ; i++)
			if (in[i] != out[i])
				return 0;
		vector<bool> visited(26, false);
		int i;
		for (i = 0 ; i < 26 ; i++)
			if (in[i])
				break;
		dfs(i, visited);
		for (int i = 0 ; i < 26 ; i++)
			if (in[i] && visited[i] == false)
				return 0;
		return 1;
	}
};