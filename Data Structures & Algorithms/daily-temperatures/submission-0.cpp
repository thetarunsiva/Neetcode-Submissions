class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tt) {
        stack<int> st;
        vector<int> aa(tt.size(), 0);
        for (int i = 0; i < tt.size(); i++) {
            for (int j = i+1; j < tt.size(); j++) {
                if (tt[j] > tt[i]) {
                    aa[i] = j-i;
                    break;
                }
            }
        }
        return aa;
    }
};
