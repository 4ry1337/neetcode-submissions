class Solution {
 public:
  /* int hammingWeight(int n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      if ((1 << i) & n) res++;
    }
    return res;
  } */
  int hammingWeight(int n) {
    int res = 0;
    while (n) {
      n &= n - 1;
      res++;
    }
    return res;
  }
};
