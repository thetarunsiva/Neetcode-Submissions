class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int i = 0; 
        int j = n - 1;
        vector<int> trapped_waterr(n, 0);
        vector<int> pff(n, 0);
        vector<int> sff(n, 0);
        for (int i = 1; i < n; i++) {
            pff[i] = max(pff[i-1], h[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            sff[i] = max(sff[i+1], h[i+1]);
        }
        for (int i = 1; i < n-1; i++) {
            int l_max = pff[i];
            int r_max = sff[i];
            int curr = max(0,  min(l_max, r_max) - h[i]);
            trapped_waterr[i] = curr;
        }
        int ans = accumulate(trapped_waterr.begin(), trapped_waterr.end(), 0);
        return ans;
    }
};
