class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 0;
        int fut = nums[0];
        int posi = nums[0];
        int ans = 1;

        for(int i=1;i<n;i++){
            if (posi < i){
                posi = fut;
                ans++;
            }
            fut = max(fut,i+nums[i]);
        }

        return ans;
    }
};
