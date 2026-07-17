class Solution {
public:
    int rows, cols;
    vector<vector<int>> h;
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;
    vector<vector<int>> a;
    vector<int> dr = {0,0,-1,1};
    vector<int> dc = {-1,1,0,0};
    void dfs(int r, int c, vector<vector<int>>& ocean) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }
        if (ocean[r][c]) {
            return;
        }
        ocean[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                continue;
            }
            if (h[nr][nc] >= h[r][c]) {
                dfs(nr, nc, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        rows = heights.size();
        cols = heights[0].size();
        pacific = vector<vector<int>>(rows, vector<int>(cols, 0));
        atlantic = vector<vector<int>>(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, pacific);
        }
        for (int i = 0; i < cols; i++) {
            dfs(0, i, pacific);
        }
        for (int i = 0; i < cols; i++) {
            dfs(rows-1, i, atlantic);
        }
        for (int i = 0; i < rows; i++) {
            dfs(i, cols-1, atlantic);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] == atlantic[i][j] && pacific[i][j]) {
                    a.push_back({i, j});
                }
            }
        }
        return a;
    }
};
