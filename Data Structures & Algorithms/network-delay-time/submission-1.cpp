class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n+1, vector<pair<int, int>>());
        for (vector<int> v : times) {
            int start = v[0];
            int end = v[1];
            int weight = v[2];
            g[start].push_back({end, weight});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0; // Root node..
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[k], k});
        while (!pq.empty()) {
            int curr = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for (pair<int, int> neighbor : g[curr]) {
                int new_node = neighbor.first;
                int new_time = neighbor.second;
                if (dist[new_node] > new_time + time) {
                    dist[new_node] = new_time + time;
                    pq.push({dist[new_node], new_node});
                }
            }
        }
        if (find(dist.begin() + 1, dist.end(), INT_MAX) != dist.end()) {
            return -1;
        }
        return *max_element(dist.begin() + 1, dist.end());
    }
};
