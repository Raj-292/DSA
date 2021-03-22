#include<bits/stdc++.h>
using namespace std;

stack<string> s1;
int cnt = 0;


bool isValid(vector<vector<char>>& arr, int row, int col, vector<vector<bool>>& visited) {

    int m = arr.size();
    int n = arr[0].size();

    if (row == -1 || row == m || col == -1 || col == n || visited[row][col] == true) {
        return false;
    }

    return true;
}

bool f(vector<vector<char>>& board, string s, int ptr, vector<vector<bool>>& visited, int row, int col) {


    //base case
    // if (ptr > s.size()) {
    //     return false;
    // }


    // if (ptr == s.size() ) {
    //     return true;
    // }

    //recurive steps

    //mark visited
    visited[row][col] = true;

    bool sd = false;
    bool sl = false;
    bool sr = false;
    bool st = false;

    //check if current pos matches
    if (s[ptr] == board[row][col]) {

        cout << "compared s[ptr]: " << s[ptr] << " board[row][col] " << board[row][col] << " for ptr:" << ptr << "for row: " << row << "for col: " << col << endl;

        //down
        if (isValid(board, row + 1, col, visited)) {
            sd = f(board, s, ptr + 1, visited, row + 1, col);
            int p = ptr + 1; int r = row + 1; int c = col;
            string x = "went down with (ptr+1) value :" + to_string(p) + " row+1 value: " + to_string(r) + " col value: " + to_string(c);
            s1.push(x);
            //cout << "CNT: " << cnt << " Went down with ptr+1 = " << ptr + 1 << " row+1 = " << row + 1 << " col = " << col << endl; cnt++;
        }
        //left
        if (isValid(board, row, col - 1, visited)) {
            sl = f(board, s, ptr + 1, visited, row, col - 1);
            int p = ptr + 1; int r = row; int c = col - 1;
            string x = "went left with (ptr+1) value :" + to_string(p) + " row value: " + to_string(r) + " col-1 value: " + to_string(c);
            s1.push(x);
            //cout << "CNT: " << cnt << " Went left with ptr+1 = " << ptr + 1 << " row = " << row << " col-1 = " << col - 1 << endl; cnt++;
        }
        //right
        if (isValid(board, row, col + 1, visited)) {
            sr = f(board, s, ptr + 1, visited, row, col + 1);
            int p = ptr + 1; int r = row + 1; int c = col;
            string x = "went right with (ptr+1) value :" + to_string(p) + " row value: " + to_string(r) + " col+1 value: " + to_string(c);
            s1.push(x);
            //cout << "CNT: " << cnt << " Went rigt with ptr+1 = " << ptr + 1 << " row = " << row << " col+1 = " << col + 1 << endl; cnt++;
        }
        //top
        if (isValid(board, row - 1, col, visited)) {
            st = f(board, s, ptr + 1, visited, row - 1, col);
            int p = ptr + 1; int r = row + 1; int c = col;
            string x = "went top with (ptr+1) value :" + to_string(p) + " row-1 value: " + to_string(r) + " col value: " + to_string(c);
            s1.push(x);
            //cout << "CNT: " << cnt << " Went top with ptr+1 = " << ptr + 1 << " row-1 = " << row - 1 << " col = " << col << endl; cnt++;
        }

        if (ptr == s.size() - 1 ) {
            return true;
        }
    }

    visited[row][col] = false;

    s1.push("The path which started @ row: " + to_string(row) + " and col: " + to_string(col) + " has ended");



    return (sd || sl || sr || st);
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > visited(m, vector<bool>(n, false));

    //considering all the positions on the board as potential starting points
    bool res = false;

    if ( (m == 1 && n == 1) && word.size() == 1 ) {
        if (board[0][0] == word[0]) {
            res = true;
        }
    } else {

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "I have called f with row: " << i << " col: " << j << endl;
                if (f(board, word, 0, visited, i, j)) {
                    return true;
                }
            }
        }
    }
    return res;
}

int main() {
    // vector<vector<char> > board = {{'a', 'b', 'c'}, {'a', 'e', 'd'}, {'a', 'f', 'g'}};
    // string word = "abcdefg";
    vector<vector<char> > board = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    string word = "abcb";

    cout << "ans: " << exist(board, word) << endl;

    return 0;
}