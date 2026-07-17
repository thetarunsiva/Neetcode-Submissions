class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (auto& i : edges) {
            int pu = find(i[0]);
            int pv = find(i[1]);
            if (pu == pv) {
                return i;
            }
            parent[pv] = pu;
        }
        return {};
    }
};
