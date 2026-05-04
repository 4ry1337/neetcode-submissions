class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res(2);
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i]) > 0) {
                res[0] = mp[nums[i]];
                res[1] = i;
                break; 
            }
            mp[target-nums[i]]=i;
        }
        return res;
    }
};
