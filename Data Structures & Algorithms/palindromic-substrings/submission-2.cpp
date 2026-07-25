class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        int cc = n;
        for (int len = 2; len < n+1; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2 or dp[i+1][j-1]) {
                        dp[i][j] = true;
                        cc++;
                    }
                }
            }
        }
        return cc;
    }
};
