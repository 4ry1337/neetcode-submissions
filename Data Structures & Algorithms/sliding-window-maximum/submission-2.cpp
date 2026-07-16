class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& n, int k) {
    vector<int> res;
    int l = 0, r = 0;
    deque<int> max_i;
    while (r < n.size()) {
      while (!max_i.empty() && n[max_i.back()] < n[r]) max_i.pop_back();
      max_i.push_back(r);
      while (l > max_i.front()) max_i.pop_front();
      if (r - l + 1 == k) {
        res.push_back(n[max_i.front()]);
        l++;
      }
      r++;
    }
    return res;
  }
};
