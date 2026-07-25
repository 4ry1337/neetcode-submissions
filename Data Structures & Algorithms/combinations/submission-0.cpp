class Solution {
 private:
  void search(int n, int k, vector<int>& subset, vector<vector<int>>& res,
              int idx) {
    if (subset.size() == k) {
      res.push_back(subset);
      return;
    }
    if (idx == n) return;
    search(n, k, subset, res, idx + 1);
    subset.push_back(idx + 1);
    search(n, k, subset, res, idx + 1);
    subset.pop_back();
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> subset;
    search(n, k, subset, res, 0);
    return res;
  }
};
