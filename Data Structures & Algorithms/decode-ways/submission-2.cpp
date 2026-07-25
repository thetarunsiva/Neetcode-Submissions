class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0); // dp[i] Represents number of ways for split till i..
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            // Single digit check..
            if (i == 0) {
                if (s[i] > '0' && s[i] <= '9') {
                    dp[i+1] += dp[i];
                }
                else {
                    dp[i+1] = 0;
                }
                continue;
            }
            if (s[i] > '0' && s[i] <= '9') {
                dp[i+1] += dp[i];
            }
            int two_digits = (s[i-1]-'0')*10 + (s[i]-'0');
            // Two digit check..
            if (two_digits >= 10 && two_digits <= 26) {
                dp[i+1] += dp[i-1];
            }
        }
        return dp[n];
    }
};
