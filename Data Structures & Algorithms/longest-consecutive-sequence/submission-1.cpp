class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> a;
        if (s.size() == 0) {
            return 0;
        }
        for (int i : s) {
            a.push_back(i);
        }
        sort(a.begin(), a.end());
        for (int i : a) cout << i << " ";
        int ma = 1;
        int temp = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i]-a[i-1] == 1) {
                temp++;
            }
            else {
                ma = max(ma, temp);
                temp = 1;
            }
        }
        ma = max(ma, temp);
        return ma;
    }
};
