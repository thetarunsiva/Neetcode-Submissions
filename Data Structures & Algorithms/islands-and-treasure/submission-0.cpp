class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    continue;
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int nr, nc;
            for (int i = 0; i < 4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                    continue;
                }
                if (grid[nr][nc] != INT_MAX) {
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
