class Solution {
 public:
  /* vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> mp(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i <= nums.size(); ++i) {
      if (mp.find(i) == mp.end()) {
        res.push_back(i);
      }
    }
    return res;
  } */
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i{}; i < nums.size(); ++i) {
      int temp = abs(nums[i]) - 1;
      if (nums[temp] > 0) nums[temp] *= -1;
    }
    vector<int> res;
    for (int i{}; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    };
    return res;
  }
};
