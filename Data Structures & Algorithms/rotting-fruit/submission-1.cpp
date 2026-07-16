class Solution {
public:
    int fresh = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        int cc = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int ss = q.size();    // Used for keeping track of layers instead of each rotten orange
            for (int j = 0; j < ss; j++) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                        continue;
                    }
                    if (grid[nr][nc] != 1) {
                        continue;
                    }
                    fresh--;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            cc++;
        }
        if (fresh) {
            return -1;
        }
        else {
            return cc;
        }
    }
};
