class Solution {
public:
    string ss;
    int rows;
    int cols;
    bool final = false;
    vector<vector<char>> b;
    void back(int i, int j, string s, vector<vector<bool>> fill) {
        if (b[i][j] != ss[s.size()]) return;
        fill[i][j] = true;
        s += b[i][j];
        if (s.size() == ss.size()) {
            if (ss == s) {
                final = true;
            }
            return;
        }
        if (i+1 < rows && !fill[i+1][j]) {
            back(i+1, j, s, fill);
        }
        if (i-1 >= 0 && !fill[i-1][j]) {
            back(i-1, j, s, fill);
        }
        if (j+1 < cols && !fill[i][j+1]) {
            back(i, j+1, s, fill);
        }
        if (j-1 >= 0 && !fill[i][j-1]) {
            back(i, j-1, s, fill);
        }
        s.pop_back();
        fill[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ss = word;
        b = board;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vector<vector<bool>> fill(rows, vector<bool>(cols, false));
                back(i, j, "", fill);
            }
        }
        return final;
    }
};
