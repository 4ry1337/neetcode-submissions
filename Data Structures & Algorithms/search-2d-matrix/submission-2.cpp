class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& m, int t) {
    int base = 0;
    int size = m.size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (m[mid][0] == t) {
        return true;
      } else if (t > m[mid][0]) {
        base = mid;
      }
      size -= half;
    }
    auto& row = m[base];
    base = 0;
    size = m[base].size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (row[mid] == t) {
        return true;
      } else if (t > row[mid]) {
        base = mid;
      }
      size -= half;
    }
    if (row[base] == t) return true;
    return false;
  }
};
