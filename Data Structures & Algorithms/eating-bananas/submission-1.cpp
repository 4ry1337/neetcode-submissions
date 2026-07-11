class Solution {
 public:
  int minEatingSpeed(vector<int>& p, int h) {
    int base = 1;
    int size = 0;
    for (auto& x : p) size = max(size, x);
    size--;
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      long long val = 0;
      for (int x : p) {
        val += ceil(static_cast<double>(x) / mid);
      }
      if (val > h) {
        base = mid;
      }
      size -= half;
    }
          long long val = 0;
      for (int x : p) {
        val += ceil(static_cast<double>(x) / base);
      }
    return base + (val >= h);
  }
};
