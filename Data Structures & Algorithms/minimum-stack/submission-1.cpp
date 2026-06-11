class MinStack {
public:
    int mi = INT_MAX;
    vector<int> st;
    vector<int> pff;
    MinStack() {
    }
    
    void push(int val) {
        mi = min(mi, val);
        pff.push_back(mi);
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        pff.pop_back();
        mi = INT_MAX;
        for (int i = 0; i < st.size(); i++) {
            mi = min(mi, st[i]);
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return pff.back();
    }
};
