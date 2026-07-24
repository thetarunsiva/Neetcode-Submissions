class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i]=1;
        }
        int start = 0; 
        int maxLen = 1;
        for (int i = 2; i < n+1; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                int k = j + i - 1;
                if (s[j] == s[k]) {
                    if (i == 2) {
                        dp[j][k] = true;
                    }
                    else {
                        dp[j][k] = dp[j+1][k-1];
                    }
                    if (dp[j][k] && i > maxLen) {
                        maxLen = i;
                        start = j;
                    }
                }
            }
        }
        string ans = s.substr(start, maxLen);
        return ans;
    }
};