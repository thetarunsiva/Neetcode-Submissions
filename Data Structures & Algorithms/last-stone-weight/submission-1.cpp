class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for (int i : stones) pq.push(i);
        while (pq.size() > 2) {
            int heaviest = pq.top();
            pq.pop();
            int heavy = pq.top();
            pq.pop();
            if (heavy != heaviest) {
                heaviest -= heavy;
                pq.push(heaviest);
                cout << heaviest << " ";
            }
            else {
                pq.push(0);
            }
        }
        int heaviest = pq.top();
        pq.pop();
        int heavy = pq.top();
        pq.pop();
        if (heaviest == heavy) {
            return 0;
        }
        else {
            cout << heaviest << " " << heavy;
            return heaviest - heavy;
        }
    }
};
