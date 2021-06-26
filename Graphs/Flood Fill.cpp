class Solution {
public:

    void helper(vector<vector<int>>& image, int sr, int sc, int newColor, int& startColor, vector<vector<bool>>& visited, vector<vector<int>>& res) {

        int m = image.size();
        int n = image[0].size();

        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != startColor || visited[sr][sc])
            return ;

        visited[sr][sc] = true;

        res[sr][sc] = newColor;

        helper(image, sr - 1, sc, newColor, startColor, visited, res);
        helper(image, sr + 1, sc, newColor, startColor, visited, res);
        helper(image, sr, sc - 1, newColor, startColor, visited, res);
        helper(image, sr, sc + 1, newColor, startColor, visited, res);

    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> res = image;

        int startColor = image[sr][sc];

        vector<vector<bool> > visited (m, vector<bool>(n, false));

        helper(image, sr, sc, newColor, startColor, visited, res);

        return res;
    }
};

// Accepted 8 ms , 14.1 MB