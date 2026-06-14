class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tt) {
        stack<int> st;
        st.push(0);
        vector<int> aa(tt.size(), 0);
        for (int i = 1; i < tt.size(); i++) {
            if (tt[st.top()] < tt[i]) {
                while (!st.empty() && tt[st.top()] < tt[i]) {
                    int curr_i = st.top();
                    st.pop();
                    aa[curr_i] = i-curr_i;
                }
                st.push(i);
            }
            else {
                st.push(i);
            }
        }
        return aa;
    }
};
