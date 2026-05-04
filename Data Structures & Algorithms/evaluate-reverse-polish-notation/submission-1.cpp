class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> se = {"+", "-", "*", "/"};
        for(auto s : tokens) {
            if(se.count(s)) {
                int r = st.top(); 
                st.pop();
                int l = st.top();
                st.pop();
                if(s == "+") st.push(l + r);
                if(s == "-") st.push(l - r);
                if(s == "*") st.push(l * r);
                if(s == "/") st.push(l / r);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
