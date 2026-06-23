class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ss = nums[0];
        int tt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tt = max(nums[i], tt+nums[i]);
            ss = max(ss, tt);
        }
        return ss;
    }
};
