class Solution {
 public:
  int climbStairs(int n) {
    if(n==1) return 1;
    int pp = 1;
    int p = 2;
    for (int i{3}; i <= n; ++i) {
      int prev = p;
      p += pp;
      pp = prev;
    }
    return p;
  }
};
