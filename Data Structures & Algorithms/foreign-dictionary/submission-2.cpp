class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> g;
        int n = words.size();
        set<char> ss;
        for (int i = 0; i < n-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int ff = 0;
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    if (!g[w1[j]].contains(w2[j])) {
                        g[w1[j]].insert(w2[j]);
                    }
                    ff = 1;
                    break;
                }
            }
            if (ff == 0 && w2.size() < w1.size()) {
                return "";
            }
        }
        for (int i = 0; i < n; i++) {
            for (char j : words[i]) {
                ss.insert(j);
            }
        }
        // Indegree cal..
        
        vector<int> indegree(26, 0);
        for (auto [ch, neighbors] : g) {
            for (char i : neighbors) {
                indegree[i-'a']++;
            }
        }
        // Topo..
        queue<char> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && ss.contains(i+'a')) {
                q.push(i+'a');
            }
        }
        string s = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            s += curr;
            for (char neighbor : g[curr]) {
                indegree[neighbor-'a']--;
                if (indegree[neighbor-'a'] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (ss.size() != s.size()) {
            return ""; // Cyclee ooooooo
        }
        return s;
    }
};
