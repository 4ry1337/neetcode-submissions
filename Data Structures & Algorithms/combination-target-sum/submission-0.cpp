class Solution {
 private:
  void backtrack(vector<int>& nums, int t, vector<vector<int>>& res,
                 vector<int>& subset, int idx) {
    if (t < 0) {
      return;
    } else if (t == 0) {
      res.push_back(subset);
      return;
    }
    for (int i{idx}; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      backtrack(nums, t - nums[i], res, subset, i);
      subset.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& nums, int t) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(nums, t, res, subset, 0);
    return res;
  }
};
