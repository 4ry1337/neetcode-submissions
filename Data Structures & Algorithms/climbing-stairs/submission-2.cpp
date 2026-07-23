class Solution {
 public:
  int climbStairs(int n) {
    int pp = 1;
    int p = 1;
    for (int i{}; i < n - 1; ++i) {
      int prev = p;
      p += pp;
      pp = prev;
    }
    return p;
  }
};
