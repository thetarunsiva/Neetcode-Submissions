class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> s;
        for (int i = 0; i < position.size(); i++) {
            pair<int, int> curr = {position[i], speed[i]};
            s.push_back(curr);
        }
        int cc = 1;
        sort(s.begin(), s.end(), greater<pair<int, int>>());
        vector<double> a;
        for (pair<int, int> i : s) {
            double curr = (double)(target - i.first) / i.second;
            a.push_back(curr);
        }
        double curr = a[0];
        for (int i = 1; i < a.size(); i++) {
            if (a[i] > curr) {
                cc++;
                curr = a[i];
            }
        }
        return cc;
        // ..
    }
};
