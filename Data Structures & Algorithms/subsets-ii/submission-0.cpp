class Solution {
 private:
  void backtrack(int k, vector<int>& nums, vector<int>& subset,
                 set<vector<int>>& res) {
    if (k == nums.size()) {
      res.insert(subset);
      return;
    }
    backtrack(k + 1, nums, subset, res);
    subset.push_back(nums[k]);
    backtrack(k + 1, nums, subset, res);
    subset.pop_back();
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    vector<int> subset;
    backtrack(0, nums, subset, res);
    return vector<vector<int>>{res.begin(), res.end()};
  }
};
