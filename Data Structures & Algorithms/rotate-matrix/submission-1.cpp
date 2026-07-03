class Solution {
 public:
  void rotate(vector<vector<int>>& m) {
    int l = m.size();
    for (int i{}; i < l; ++i) {
      for (int j{}; j < l - 1 - i; ++j) {
        swap(m[i][j], m[l - 1 - j][l - 1 - i]);
      }
    }
    for (int i{}; i < l / 2; ++i) {
      for (int j{}; j < l; ++j) {
        swap(m[i][j], m[l - 1 - i][j]);
      }
    }
  }
};
