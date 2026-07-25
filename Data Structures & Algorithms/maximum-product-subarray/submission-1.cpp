class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ma = nums[0];
        int mi = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int oldMa = ma;
            int oldMi = mi;
            ma = max({nums[i], oldMa*nums[i], oldMi*nums[i]});
            mi = min({nums[i], oldMa*nums[i], oldMi*nums[i]});
            ans = max(ans, ma);
        }
        return ans;
    }
};
