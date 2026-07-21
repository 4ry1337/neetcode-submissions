class Solution {
 public:
  /* int findKthLargest(vector<int>& nums, int k) {
    sort(nums.rbegin(), nums.rend());
    return nums[k - 1];
  } */
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    while (--k) pq.pop();
    return pq.top();
  }
};
