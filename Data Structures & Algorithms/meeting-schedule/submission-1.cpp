/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> st;
        for (auto i : intervals) {
            int st_element = i.start;
            int en_element = i.end;
            st.push_back({st_element, en_element});
        }
        sort(st.begin(), st.end());
        for (int i = 1; i < st.size(); i++) {
            pair<int, int> next = st[i];
            pair<int, int> curr = st[i-1];
            if (next.first < curr.second) {
                return false;
            }
        }
        return true;
    }
};
