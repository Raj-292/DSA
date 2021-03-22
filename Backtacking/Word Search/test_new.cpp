class Solution {
public:

    bool isValid(vector<vector<char>>& arr, int row, int col, vector<vector<bool>>& visited, string& s) {

        int m = arr.size();
        int n = arr[0].size();

        if (row == -1 || row == m || col == -1 || col == n || visited[row][col] == true || s[ptr] != arr[row][col] ) {
            return false;
        }

        return true;
    }

    bool f(vector<vector<char>>& board, string& s, int ptr, vector<vector<bool>>& visited, int row, int col) {


        //base case

        //mark visited
        visited[row][col] = true;


        //check validity for starting pos





        bool sd = false;
        bool sl = false;
        bool sr = false;
        bool st = false;

        //check if current pos matches

        //down
        if (isValid(board, row + 1, col, visited, s)) {
            sd = f(board, s, ptr + 1, visited, row + 1, col);
        }
        //left
        if (isValid(board, row, col - 1, visited, s)) {
            sl = f(board, s, ptr + 1, visited, row, col - 1);
        }
        //right
        if (isValid(board, row, col + 1, visited, s)) {
            sr = f(board, s, ptr + 1, visited, row, col + 1);
        }
        //top
        if (isValid(board, row - 1, col, visited, s)) {
            st = f(board, s, ptr + 1, visited, row - 1, col);
        }

        visited[row][col] = false;

        return (sd || sl || sr || st);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));


        bool res = false;

        //considering all the positions on the board as potential starting points
        if ( (m == 1 && n == 1) && word.size() == 1 ) {
            if (board[0][0] == word[0]) {
                res = true;
            }
        } else {

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (f(board, word, 0, visited, i, j)) {
                        return true;
                    }
                }
            }
        }
        return res;
    }
};