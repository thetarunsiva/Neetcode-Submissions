class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for (int i : stones) pq.push(i);
        while (pq.size() > 1) {
            int heaviest = pq.top();
            pq.pop();
            int heavy = pq.top();
            pq.pop();
            if (heavy != heaviest) {
                heaviest -= heavy;
                pq.push(heaviest);
            }
        }
        if (pq.size() == 0) return 0;
        else {
            return pq.top();
        }
    }
};
