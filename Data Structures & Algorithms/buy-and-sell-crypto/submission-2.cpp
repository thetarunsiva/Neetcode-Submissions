class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int i = 1;
        int leftMin = p[0];
        int maxProfit = 0;
        while (i < n) {
            leftMin = min(leftMin, p[i-1]);
            int currProfit = max(0, p[i] - leftMin);
            maxProfit = max(maxProfit, currProfit);
            i++;
        }
        return maxProfit;
    }
};
