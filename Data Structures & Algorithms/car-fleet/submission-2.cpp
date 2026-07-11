class Solution {
 public:
  int carFleet(int t, vector<int>& p, vector<int>& s) {
    vector<pair<int, int>> ps;
    for (size_t i{}; i < p.size(); ++i) ps.push_back({p[i], s[i]});
    sort(ps.rbegin(), ps.rend());
    stack<double> st;
    for (auto& [pos, sp] : ps) {
      double time = (double)(t - pos) / sp;
      if (!st.empty() && st.top() >= time) continue;
      st.push(time);
    }
    return st.size();
  }
};
