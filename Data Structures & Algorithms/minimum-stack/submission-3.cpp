class MinStack {
public:
    int mi;
    vector<int> st;
    vector<int> pff;
    MinStack() {
    }
    
    void push(int val) {
        if (pff.empty()) {
            pff.push_back(val);
        }
        else {
            pff.push_back(min(val, pff.back()));
        }
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        pff.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return pff.back();
    }
};
