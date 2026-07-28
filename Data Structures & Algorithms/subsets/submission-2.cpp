class Solution {
 private:
  void backtrack(int k, vector<int>& nums, vector<int>& subset,
                 vector<vector<int>>& res) {
    if (k == nums.size()) {
      res.push_back(subset);
      return;
    }
    backtrack(k + 1, nums, subset, res);
    subset.push_back(nums[k]);
    backtrack(k + 1, nums, subset, res);
    subset.pop_back();
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    backtrack(0, nums, subset, res);
    return res;
  }
};
