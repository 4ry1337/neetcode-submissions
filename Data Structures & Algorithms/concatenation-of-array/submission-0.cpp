class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans.resize(2 * nums.size());
        for(size_t i{}; i< nums.size(); ++i) {
            ans[i] = ans[i+nums.size()] = nums[i];
        }
        return ans;
    }
};