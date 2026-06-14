class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> left(h.size()), right(h.size());
        stack<int> st;
        
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            right[st.top()] = h.size();
            st.pop();
        }

        for (int i = h.size()-1; i >= 0; i--) {
            while (!st.empty() && h[i] < h[st.top()]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        int ma = 0;
        for (int i = 0; i < h.size(); i++) {
            int curr = h[i] * (right[i] - left[i] - 1);
            ma = max(ma, curr);
        }
        return ma;
    }
};