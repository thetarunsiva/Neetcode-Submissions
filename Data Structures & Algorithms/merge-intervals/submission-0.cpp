class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i+1][0] <= intervals[i][1]) {
                int end = max(intervals[i][1], intervals[i+1][1]);
                intervals[i] = {intervals[i][0], end};
                intervals.erase(intervals.begin() + i+1);
                // Noo increment cuz we gotta compare the new merge interval with the immediate next..
            }
            else {
                i++;
            }
        }
        return intervals;
    }
};
