class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        unordered_set<string> words(w.begin(), w.end());
        if (!words.contains(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int cc = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) {
                    return cc;
                }
                for (int i = 0; i < curr.size(); i++) {
                    char original = curr[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;
                        curr[i] = ch;
                        if (words.contains(curr)) {
                            q.push(curr);
                            words.erase(curr); // Instead of a separate visitted array..
                        }
                    }
                    curr[i] = original;
                }
            }
            cc++;
        }
        return 0;
    }
};
