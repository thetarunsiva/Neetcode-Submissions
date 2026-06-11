class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n <= 1) return n;
        int i = 0;
        int maxF = 0;
        int ll = 0;
        unordered_map<char, int> mpp;
        for (int j = 0; j < n; j++) {
            mpp[s[j]]++;
            maxF = max(maxF, mpp[s[j]]);
            while ((j - i + 1) - maxF > k) {
                mpp[s[i]]--;
                i++;
            }
            ll = max(ll, j - i + 1);
        }
        return ll;
    }
};
