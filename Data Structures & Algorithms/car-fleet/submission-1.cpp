class Solution {
public:
    int carFleet(int k, vector<int>& p, vector<int>& s) {
        int n = p.size();
        
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; i++) temp[i] = {p[i], s[i]};
        sort(temp.rbegin(), temp.rend());
        
        stack<double> st;
        for(int i = 0; i < n; i++) {
            double t = (double)(k - temp[i].first) / temp[i].second;
            if(st.empty() || st.top() < t) {
                st.push(t);
            }
        }
        return st.size();
    }
};
