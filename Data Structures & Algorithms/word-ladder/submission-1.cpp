class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        if (find(w.begin(), w.end(), endWord) == w.end()) {
            return 0;
        }
        unordered_map<string, vector<string>> g;
        for (string root : w) {
            g[root] = {};
            for (string another: w) {
                int cc = 0;
                for (int i = 0; i < beginWord.size(); i++) {
                    if (root[i] != another[i]) cc++;
                    if (cc > 1) {
                        break;
                    }
                }
                if (cc == 1) {
                    g[root].push_back(another);
                }
            }
            int cc = 0;
            for (int i = 0; i < beginWord.size(); i++) {
                if (root[i] != beginWord[i]) cc++;
                    if (cc > 1) {
                        break;
                    }
                }
            if (cc == 1) {
                g[root].push_back(beginWord);
            }
        }
        int cc = 0;
        queue<string> q;
        unordered_map<string, bool> visited;
        visited[beginWord] = false;
        for (int i = 0; i < w.size(); i++) {
            visited[w[i]] = false;
        }
        q.push(endWord);
        visited[endWord] = true;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string curr = q.front();
                q.pop();
                if (curr == beginWord) {
                    return cc + 1;
                }
                for (string neighbor : g[curr]) {
                    if (visited[neighbor] == false) {
                        q.push(neighbor);
                        visited[curr] = true;
                    }
                }
            }
            cc++;
        }
        return 0;
    }
};
