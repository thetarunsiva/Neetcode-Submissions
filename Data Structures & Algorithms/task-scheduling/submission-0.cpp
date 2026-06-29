class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int min_time = tasks.size();
        unordered_map<char, int> mpp;
        priority_queue<pair<int, char>> pq;
        for (int i : tasks) mpp[i]++;
        for (auto i : mpp) {
            int ff = i.second;
            int cc = i.first;
            pair<int, char> curr = {ff, cc};
            pq.push(curr);
        }
        int ma = pq.top().first;
        int ma_count = 1;
        pq.pop();
        while (!pq.empty() && pq.top().first == ma) {
            ma_count++;
            pq.pop();
        }
        int schedule = (ma-1) * (n+1) + ma_count;
        int ans = max(min_time, schedule);
        return ans;
    }
};
