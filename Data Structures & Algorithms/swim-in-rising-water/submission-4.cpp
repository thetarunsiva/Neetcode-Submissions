class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int l = 0;
        int r = n*n;
        int ans = r; // Set worst..
        function<bool(int, int, int)> dfs = [&](int i, int j, int val) {
            if (i < 0 || i > n-1 || j < 0 || j > n-1 || visited[i][j] || val < grid[i][j]) {
                return false;
            }
            visited[i][j] = 1;
            if (i == n-1 && j == n-1) return true;
            return dfs(i+1, j, val) || dfs(i, j+1, val) || dfs(i, j-1, val) || dfs(i-1, j, val);
        };
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dfs(0, 0, mid)) {   // Update only if case passes..
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    visited[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
