class Solution {
 public:
  /* vector<int> countBits(int n) {
    vector<int> res;
    for (int i{}; i <= n; ++i) res.push_back(__builtin_popcount(i));
    return res;
  } */
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
      int offset = 1;
      while (offset * 2 <= i) offset *= 2;
      res[i] = 1 + res[i - offset];
    }
    return res;
  }
};
