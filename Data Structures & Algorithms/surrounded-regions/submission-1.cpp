class Solution {
public:
    vector<vector<char>> b;
    vector<vector<int>> safe;
    vector<int> dr = {0,0,-1,1};
    vector<int> dc = {-1,1,0,0};
    int rows, cols;
    void dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }
        if (safe[r][c] || b[r][c] == 'X') {
            return;
        }
        safe[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            dfs(nr, nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        b = board;
        safe = vector<vector<int>>(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            if (b[i][0] == 'O') {
                dfs(i, 0);
            }
        }
        for (int i = 0; i < cols; i++) {
            if (b[0][i] == 'O') {
                dfs(0, i);
            }
        }
        for (int i = 0; i < rows; i++) {
            if (b[i][cols-1] == 'O') {
                dfs(i, cols-1);
            }
        }
        for (int i = 0; i < cols; i++) {
            if (b[rows-1][i] == 'O') {
                dfs(rows-1, i);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (safe[i][j] == 0 && b[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
            }
        }
        return;
    }
};
