class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size(), 0);
        stack<pair<int, int>> st;
        for(int i = 0; i < t.size(); i++) {
            int x = t[i];
            while(!st.empty() && st.top().first < x) {
                auto p = st.top();
                st.pop();
                res[p.second] = i - p.second;
            }
            st.push({x, i});
        }
        return res;
    }
};
