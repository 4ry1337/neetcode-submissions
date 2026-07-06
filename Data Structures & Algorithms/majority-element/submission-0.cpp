class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0, cnd;
    for (auto& n : nums) {
      if (count == 0) {
        cnd = n;
      }
      count += (cnd == n) ? 1 : -1;
    }
    return cnd;
  }
};
