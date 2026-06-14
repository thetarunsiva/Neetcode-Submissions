class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int cc = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "/" && tokens[i] != "*" && tokens[i] != "-") {
                st.push(tokens[i]);
            }
            else {
                string n1, n2;
                if (tokens[i] == "+") {
                    n2 = st.top();
                    st.pop();
                    n1 = st.top();
                    st.pop();
                    int num2 = stoi(n2);
                    int num1 = stoi(n1);
                    int tt = num1 + num2;
                    string cc = to_string(tt);
                    st.push(cc);
                }
                if (tokens[i] == "-") {
                    n2 = st.top();
                    st.pop();
                    n1 = st.top();
                    st.pop();
                    int num2 = stoi(n2);
                    int num1 = stoi(n1);
                    int tt = num1 - num2;
                    string cc = to_string(tt);
                    st.push(cc);
                }
                if (tokens[i] == "*") {
                    n2 = st.top();
                    st.pop();
                    n1 = st.top();
                    st.pop();
                    int num2 = stoi(n2);
                    int num1 = stoi(n1);
                    int tt = num1 * num2;
                    string cc = to_string(tt);
                    st.push(cc);
                }
                if (tokens[i] == "/") {
                    n2 = st.top();
                    st.pop();
                    n1 = st.top();
                    st.pop();
                    int num2 = stoi(n2);
                    int num1 = stoi(n1);
                    int tt = num1 / num2;
                    string cc = to_string(tt);
                    st.push(cc);
                }
            }
        }
        int aa = stoi(st.top());
        return aa;
    }
};
