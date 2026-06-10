class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0; 
        int j = h.size()-1;
        int ma = 0;
        while (i < j) {
            int curr_h = min(h[i], h[j]);
            int curr_b = j - i;
            int area = curr_h * curr_b;
            ma = max(ma, area);
            if (h[i] >= h[j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return ma;
    }
};
