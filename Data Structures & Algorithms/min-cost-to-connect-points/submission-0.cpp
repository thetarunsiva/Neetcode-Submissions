class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) {
            parent[pi] = pj;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        vector<int> p(points.size());
        for (int i = 0; i < points.size(); i++) p[i] = i;
        parent = p;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        int ans = 0;
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); i++) {
            if (find(edges[i][1])!=find(edges[i][2])){
                merge(edges[i][1],edges[i][2]);
                ans+=edges[i][0];
            }
        }
        return ans;

    }
};
