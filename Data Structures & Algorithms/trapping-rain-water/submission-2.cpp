class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int i = 0; 
        int j = n - 1;
        int max_left = 0;
        int max_right = 0;
        int ans = 0;
        while (i < j) {
            max_left = max(max_left, h[i]);
            max_right = max(max_right, h[j]);
            if (max_left <= max_right) {
                ans += max_left - h[i];
                i++;
            }
            else {
                ans += max_right - h[j];
                j--;
            }
        }
        return ans;
    }
};
