class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        while(r < nums.size()) {
            if(l < 2 || nums[r] != nums[l-2]) {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};

// 1 1 2 2 2 3
//         l
//           r