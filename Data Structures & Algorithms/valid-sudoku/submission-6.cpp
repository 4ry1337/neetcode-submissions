class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    array<array<int, 9>, 9> rows{};
    array<array<int, 9>, 9> cols{};
    array<array<int, 9>, 9> grid{};
    for (int i{}; i < 9; ++i) {
      for (int j{}; j < 9; ++j) {
        if (board[i][j]=='.') continue;
        if (++rows[i][board[i][j] - '1'] > 1) return false;
        if (++cols[j][board[i][j] - '1'] > 1) return false;
        if (++grid[(i / 3) * 3 + (j / 3)][board[i][j] - '1'] > 1) return false;
      }
    }
    return true;
  }
};
