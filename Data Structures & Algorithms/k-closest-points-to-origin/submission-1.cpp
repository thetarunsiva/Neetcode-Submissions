class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> a;
        int kk = k;
        int i = 0;
        priority_queue<pair<int, vector<int>>> dpp;
        while (dpp.size() < kk) {
            int x = points[i][0];
            int y = points[i][1];
            int d = (x*x + y*y);
            pair<int, vector<int>> pp = {d, points[i]};
            dpp.push(pp);
            i++;
        }
        for (int j = i; j < points.size(); j++) {
            int x = points[j][0];
            int y = points[j][1];
            int d = (x*x + y*y);
            if (d < dpp.top().first) {
                pair<int, vector<int>> pp = {d, points[j]};
                dpp.pop();
                dpp.push(pp);
            }
        }
        while (dpp.size()) {
            pair<int, vector<int>> curr = dpp.top();
            dpp.pop();
            a.push_back(curr.second);
        }
        return a;
    }
};
