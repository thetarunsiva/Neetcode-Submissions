class Solution {
public:
    int rows, cols;
    vector<vector<char>> g;
    vector<vector<int>> vis;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    void dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }
        if (vis[r][c]) {
            return;
        }
        if (g[r][c] == '0') {
            return;
        }
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i]);
        }
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
