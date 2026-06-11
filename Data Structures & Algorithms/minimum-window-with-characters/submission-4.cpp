class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> need(128, 0);
        for (char i : t) need[i]++;
        int still = t.size();
        int i = 0;
        int ll = INT_MAX;
        int st = 0;
        string ss;
        for (int j = 0; j < s.size(); j++) {
            if (need[s[j]] > 0) {
                still--;
            }
            need[s[j]]--;
            while (still == 0) {
                if (j - i + 1 < ll) {
                    ll = j - i + 1;
                    st = i;
                }
                need[s[i]]++;
                if (need[s[i]] > 0) {
                    still++;
                }
                i++;
            }
        }
        if (ll == INT_MAX) {
            return "";
        }
        ss = s.substr(st, ll);
        return ss;
    }
};
