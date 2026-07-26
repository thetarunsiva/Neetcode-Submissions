class Solution {
public:
    int n;
    vector<string> ans = {};
    vector<vector<string>> ticket;
    unordered_map<string, vector<pair<string, int>>> graph;
    vector<bool> visited;
    void dfs(vector<string> path) {
        if (!ans.empty()) {
            return;
        }
        if (path.size() == ticket.size() + 1) {
            ans = path;
            return;
        }
        string curr = path.back();
        for (pair<string, int> i : graph[curr]) {
            int ticket_id = i.second;
            string new_node = i.first;
            if (!visited[ticket_id]) {
                path.push_back(new_node);
                visited[ticket_id] = true;
                dfs(path);
                visited[ticket_id] = false;
                path.pop_back();
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        ticket = tickets;
        visited = vector<bool>(n, false);
        unordered_map<string, vector<pair<string, int>>> g;
        int tt = 0;
        for (vector<string> i : tickets) {
            string start = i[0];
            string end = i[1];
            g[start].push_back({end, tt});
            tt++;
        }
        for (auto& [node, neighbours] : g) {
            sort(neighbours.begin(), neighbours.end());
        }
        graph = g;
        dfs({"JFK"});
        return ans;
    }

};
