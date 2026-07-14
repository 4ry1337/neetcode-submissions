class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int res = 0, l = 0, r = 0;
    while (r < p.size()) {
      res = max(res, p[r] - p[l]);
      if (p[l] > p[r]) {
        l++;
      } else {
        r++;
      }
    }
    return res;
  }
};
