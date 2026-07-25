class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cc = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
        }
        for (int len = 2; len < n+1; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    cc++;
                }
            }
        }
        return cc;
    }
};
