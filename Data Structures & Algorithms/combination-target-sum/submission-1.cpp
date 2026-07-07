class Solution {
public:
    vector<vector<int>> ans;
    vector<int> num;
    int tar,n;
    void back(vector<int> cur, int s, int ind) {
        if (s == tar) {
                ans.push_back(cur);
                return;
        }
        if (s > tar || ind > n-1) {
            return;
        }
        for(int i=ind;i<n;i++){
            cur.push_back(num[i]);
            s += num[i];
            back(cur, s, i);
            cur.pop_back();
            s -= num[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        num = nums;
        tar = target;
        back({}, 0, 0);
        return ans;
    }
};
