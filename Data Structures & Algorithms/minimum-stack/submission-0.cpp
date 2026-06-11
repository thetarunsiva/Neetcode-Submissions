class MinStack {
public:
    int mi = INT_MAX;
    vector<int> st;
    MinStack() {
    }
    
    void push(int val) {
        mi = min(mi, val);
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        mi = INT_MAX;
        for (int i = 0; i < st.size(); i++) {
            mi = min(mi, st[i]);
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mi;
    }
};
