class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zz = 0;
        for (int i : nums) {
            zz ^= i;
        }
        return zz;
    }
};
