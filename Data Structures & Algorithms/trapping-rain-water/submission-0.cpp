class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int i = 0; 
        int j = n - 1;
        vector<int> trapped_waterr(n, 0);
        for (int i = 1; i < n-1; i++) {
            int lh = i-1;
            int rh = i+1;
            int l_max = 0;
            int r_max = 0;
            while (lh >= 0) {
                l_max = max(l_max, h[lh]);
                lh--;
            }
            while (rh <= n-1) {
                r_max = max(r_max, h[rh]);
                rh++;
            }
            int curr = max(0,  min(l_max, r_max) - h[i]);
            trapped_waterr[i] = curr;
        }
        int ans = accumulate(trapped_waterr.begin(), trapped_waterr.end(), 0);
        return ans;
    }
};
