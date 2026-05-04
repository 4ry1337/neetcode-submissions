class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i <= h.size(); i++) {
            while(!st.empty() && (i == h.size() || h[st.top()] > h[i])) {
                int height = h[st.top()]; st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                int width = nse - pse - 1;
                res = max(res, height * width); 
            }
            st.push(i);
        }
        return res;
    }
};
