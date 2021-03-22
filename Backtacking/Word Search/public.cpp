int x[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool inrange(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}
bool dfs(vector<vector<char>> &board, string word, int i, int j, bool**vis)
{
    if (word.size() == 1 && board[i][j] == word[0]) return true;
    if (board[i][j] != word[0]) return false;
    vis[i][j] = true;
    for (int p = 0; p < 8; p++)
    {
        if (inrange(i + x[p], j + y[p], board.size(), board[0].size()) && vis[i + x[p]][j + y[p]] == false)
        {
            bool b = dfs(board, word.substr(1), i + x[p], j + y[p], vis);
            if (b) return true;
        }
    }
    vis[i][j] = false;
    return false;
}
vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    int n = board.size();
    int m = board[0].size();
    int p = dictionary.size();
    bool ** vis = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }
    vector<string> final_ans;
    int flag;
    for (int k = 0; k < p; k++)
    {
        flag = 0;
        string word = dictionary[k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    bool b = dfs(board, word, i, j, vis);
                    if (b)
                    {
                        final_ans.push_back(word);
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
            }
        }
    }
    return final_ans;
}

0.01 AC ! DFS

//

bool vis[100][100];
bool Util(vector<vector<char> >&board, int m, int n, int x, int y, string s, int k)
{
    if (k == s.size())
        return true;
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != s[k] || vis[x][y] == true)
        return false;
    vis[x][y] = true;
    bool ul = Util(board, m, n, x - 1, y - 1, s, k + 1);
    bool u = Util(board, m, n, x - 1, y, s, k + 1);
    bool ur = Util(board, m, n, x - 1, y + 1, s, k + 1);
    bool l = Util(board, m, n, x, y - 1, s, k + 1);
    bool r = Util(board, m, n, x, y + 1, s, k + 1);
    bool dl = Util(board, m, n, x + 1, y - 1, s, k + 1);
    bool d = Util(board, m, n, x + 1, y, s, k + 1);
    bool dr = Util(board, m, n, x + 1, y + 1, s, k + 1);

    vis[x][y] = false;
    if (ul || u || ur || l || r || dl || d || dr)
        return true;
    return false;
}
vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary)
{
    // Your code goes here
    vector<string>v;
    v.clear();
    int m = board.size();
    int n = board[0].size();
    bool b = false;
    for (int i = 0; i < dictionary.size(); i++)
    {
        b = false;
        for (int p = 0; p < m; p++)
        {
            for (int q = 0; q < n; q++)
            {
                if (board[p][q] == dictionary[i][0])
                {
                    memset(vis, false, sizeof(vis));
                    if (Util(board, m, n, p, q, dictionary[i], 0))
                    {
                        v.push_back(dictionary[i]);
                        b = true;

                    }

                }
                if (b == true)
                    break;
            }
            if (b == true)
                break;
        }
    }

    return v;
}

Execution Time: 0.21