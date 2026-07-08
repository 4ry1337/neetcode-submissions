class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        priority_queue<int> mp;
        for(auto & n : nums) {
            mp.push(n);
        }
        int res = 1, m = 1, next = mp.top(); mp.pop();
        while(!mp.empty()) {
            if(mp.top() == next - 1) {
                m++;
            } else if(mp.top() != next) {
                res = max(m, res);
                m = 1;
            }
            next = mp.top();
            mp.pop();
        }
        return max(m, res);
    }
};
