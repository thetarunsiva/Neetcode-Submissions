class Solution {
public:
    int rows, cols;
    vector<vector<char>> g;
    vector<vector<int>> vis;
    void dfs(int r, int c) {
        if (r < 0 || c < 0 || r == rows || c == cols) {
            return;
        }
        if (vis[r][c]) {
            return;
        }
        if (g[r][c] == '0') {
            return;
        }
        vis[r][c] = 1;
        dfs(r, c+1);
        dfs(r, c-1);
        dfs(r+1, c);
        dfs(r-1, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        g = grid;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vis = visited;
        int cc = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!vis[i][j] && g[i][j] == '1') {
                    cc++;
                    dfs(i, j);
                }
            }
        }
        return cc;
    }
};
