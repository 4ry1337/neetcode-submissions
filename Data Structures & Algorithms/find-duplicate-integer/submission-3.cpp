class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = nums[0];
        for(int i{}; i < nums.size(); i++) {
            int next = nums[res];
            if(next == 0) return res;
            nums[res] = 0;
            res = next;
        }
        return res;
    }
};
