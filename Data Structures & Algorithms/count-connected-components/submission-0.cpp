class Solution {
public:
    vector<int> visited;
    vector<vector<int>> g;
    void dfs(int node) {
        if (visited[node]) {
            return;
        }
        visited[node] = 1;
        for (int i = 0; i < g[node].size(); i++) {
            dfs(g[node][i]);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        visited = vector<int>(n, 0);
        g = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                cc++;
                dfs(i);
            }
        }
        return cc;
    }
};
