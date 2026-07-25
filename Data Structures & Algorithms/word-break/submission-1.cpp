class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int l = 1; l <= i+1; l++) {
                string ss = s.substr(i + 1 - l, l);
                if (find(wordDict.begin(), wordDict.end(), ss) != wordDict.end() && dp[i+1 - l]) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
