class Solution {
public:
    int rows, cols;
    vector<vector<int>> g;
    vector<vector<int>> vis;
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    int a = 0;
    int dfs(int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return 0;
        }
        if (!g[r][c]) {
            return 0;
        }
        if (vis[r][c]) {
            return 0;
        }
        vis[r][c] = 1;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            area += dfs(r + dr[i], c + dc[i]);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vis = visited;
        g = grid;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (g[i][j] && !vis[i][j]) {
                    a = max(a, dfs(i, j));
                }
            }
        }
        return a;
    }
};
