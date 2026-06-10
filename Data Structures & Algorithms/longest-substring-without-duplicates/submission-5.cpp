class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int n = s.size();
        int ll = 1;
        for (int i = 0; i < n; i++) {
            set<char> a;
            a.insert(s[i]);
            for (int j = i+1; j < n; j++) {
                if (a.contains(s[j])) {
                    int cc = a.size();
                    ll = max(ll, cc);
                    break;
                }
                else {
                    a.insert(s[j]);
                }
            }
            int cc = a.size();
            ll = max(ll, cc);
        }
        return ll;
    }
};
