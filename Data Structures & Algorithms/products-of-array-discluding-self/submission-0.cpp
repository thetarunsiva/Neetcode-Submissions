class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long tt = 1;
        for (int i : nums) {
            tt *= i;
        }
        vector<int> a(nums.size());
        if (tt) {
            for (int i = 0; i < nums.size(); i++) {
                a[i] = tt / nums[i];
            }
        }
        else {
            int zz = count(nums.begin(), nums.end(), 0);
            int ss = 1;
            if (zz == 1) {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == 0) {
                        for (int j = 0; j < nums.size(); j++) {
                            if (j != i) {
                                ss *= nums[j];
                                a[j] = 0;
                            }
                        }
                        a[i] = ss;
                    }
                }
            }
            else {
                for (int i = 0; i < nums.size(); i++) a[i] = 0;
            }
        }
        return a;
    }
};
