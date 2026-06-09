class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pff(nums.size());
        vector<int> sff(nums.size());
        pff[0] = 1;
        sff[nums.size()-1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pff[i] = nums[i-1] * pff[i-1];
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            sff[i] = nums[i+1] * sff[i+1];
        }
        vector<int> a(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            a[i] = pff[i] * sff[i];
        }
        return a;
    }
};
