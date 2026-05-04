class MinStack {
private:
    stack<int> st, min;
public:
    MinStack() {}
    
    void push(int val) {
        if(min.empty() || min.top() > val) {
            min.push(val);
        } else {
            min.push(min.top());
        }
        st.push(val);
    }
    
    void pop() {
        min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
