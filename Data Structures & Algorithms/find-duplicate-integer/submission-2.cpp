class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = nums[0];
        for(int i{}; i < nums.size(); i++) {
            if(nums[res] == 0) return res;
            int next = nums[res];
            nums[res] = 0;
            res = next;
        }
        return res;
    }
};
