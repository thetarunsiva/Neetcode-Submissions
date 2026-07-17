class Solution {
public:
    vector<vector<int>> tree;
    vector<int> visited;
    void dfs(int node) {
        if (visited[node]) {
            return;
        }
        visited[node] = 1;
        for (int i = 0; i < tree[node].size(); i++) {
            dfs(tree[node][i]);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n-1 != edges.size()) {
            return false;
        }
        tree = vector<vector<int>>(n);
        visited = vector<int>(n, 0);
        for (int i = 0; i < n-1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
