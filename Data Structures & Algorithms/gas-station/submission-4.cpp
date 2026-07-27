class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x = 0;
        int n = gas.size();
        int res = 0;
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            x += gas[i] - cost[i];
            if (x < 0) {
                x = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
