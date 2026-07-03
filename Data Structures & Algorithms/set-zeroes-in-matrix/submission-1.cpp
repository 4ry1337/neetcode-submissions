class Solution {
 public:
  void setZeroes(vector<vector<int>>& m) {
    int r = m.size();
    int c = m[0].size();
    bool row = false;
    bool col = false;
    for (int i{}; i < r; ++i) {
      if (m[i][0] == 0) {
        col = true;
        break;
      };
    }
    for (int i{}; i < c; ++i) {
      if (m[0][i] == 0) {
        row = true;
        break;
      }
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (m[i][j] == 0) {
          m[i][0] = 0;
          m[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < r; ++i) {
      for (int j = 1; j < c; ++j) {
        if (m[i][0] == 0 || m[0][j] == 0) {
          m[i][j] = 0;
        }
      }
    }
    if (col) {
      for (int i{}; i < r; ++i) {
        m[i][0] = 0;
      }
    }
    if (row) {
      for (int i{}; i < c; ++i) {
        m[0][i] = 0;
      }
    }
  }
};
