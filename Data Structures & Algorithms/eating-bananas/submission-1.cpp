class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r-l)/2;
            int curr_h = 0;
            for (int i : piles) {
                int h_i = (i + mid - 1) / mid;
                curr_h += h_i;
            }
            if (curr_h <= h) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
