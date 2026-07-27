class Solution {
public:
    bool canJump(vector<int>& nums) {
        int posi = nums[0];

        for (int i=1;i<nums.size();i++){
            if (posi<i){
                return false;
            }
            posi = max(posi,i+nums[i]);
        }

        return true;
    }
};
