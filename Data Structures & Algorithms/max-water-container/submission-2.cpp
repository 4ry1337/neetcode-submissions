class Solution {
 public:
  int maxArea(vector<int>& h) {
    int res = 0, l = 0, r = h.size() - 1;
    while (l < r) {
      res = max(res, (r - l) * min(h[r], h[l]));
      if (h[l] > h[r]) {
        r--;
      } else {
        l++;
      }
    }
    return res;
  }
};
