class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        set<char> a;
        int ll = 1;
        int n = s.size();
        if (n <= 1) {
            return n;
        }
        for (int j = 0; j < n; j++) {
            while (a.contains(s[j])) {
                a.erase(s[i]);
                i++;
            }
            a.insert(s[j]);
            int cc = a.size();
            ll = max(ll, cc);
        }
        return ll;
    }
};
